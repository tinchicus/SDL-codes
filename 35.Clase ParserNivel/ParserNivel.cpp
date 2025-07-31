#include "ParserNivel.h"

Nivel* ParserNivel::parseNivel(const char* nivelArchivo) {
	TiXmlDocument nivelDocumento;
	nivelDocumento.LoadFile(nivelArchivo);

	Nivel* pNivel = new Nivel();

	TiXmlElement* pRaiz = nivelDocumento.RootElement();

	pRaiz->Attribute("tileWidth", &m_tamPatron);
	pRaiz->Attribute("width", &m_ancho);
	pRaiz->Attribute("height", &m_alto);

	for (TiXmlElement* e = pRaiz->FirstChildElement(); e != NULL;
		e = e->NextSiblingElement()) {
		if (e->Value() == std::string("tileset")) {
			parseConjuntos(e, pNivel->getConjPatron());
		}
	}
	for (TiXmlElement* e = pRaiz->FirstChildElement(); e != NULL;
		e = e->NextSiblingElement()) {
		if (e->Value() == std::string("layer")) {
			parseCapaPatron(e, pNivel->getCapas(), pNivel->getConjPatron());
		}
	}

	return pNivel;
}

void ParserNivel::parseConjuntos(TiXmlElement* pRaizConjuntos, 
	std::vector<ConjuntoPatron>* pConjuntos) {
	Elmanejador::instanciar()->cargar(
		pRaizConjuntos->FirstChildElement()->Attribute("source"),
		pRaizConjuntos->Attribute("name"),
		Eljuego::instanciar()->getRenderer());
	ConjuntoPatron conjunto;
	pRaizConjuntos->FirstChildElement()->Attribute("width",&conjunto.ancho);
	pRaizConjuntos->FirstChildElement()->Attribute("height", &conjunto.alto);
	pRaizConjuntos->Attribute("firstgrid", &conjunto.primerCuadric);
	pRaizConjuntos->Attribute("tilewidth", &conjunto.anchoPatron);
	pRaizConjuntos->Attribute("tileheight", &conjunto.altoPatron);
	pRaizConjuntos->Attribute("spacing", &conjunto.espaciado);
	pRaizConjuntos->Attribute("margin", &conjunto.margen);
	conjunto.nombre = pRaizConjuntos->Attribute("name");

	conjunto.numColumnas = conjunto.ancho / (conjunto.anchoPatron + conjunto.espaciado);

	pConjuntos->push_back(conjunto);
}

void ParserNivel::parseCapaPatron(TiXmlElement* pElemento, 
	std::vector<Capa*>* pCapas, const std::vector<ConjuntoPatron>* pConjuntos) {
	CapaPatron* pCapaPatron = new CapaPatron(m_tamPatron, *pConjuntos);
	std::vector<std::vector<int>> datos;

	std::string idDecodificados;

	TiXmlElement* pNodoDatos;

	for (TiXmlElement* e = pElemento->FirstChildElement(); e != NULL; 
		e->NextSiblingElement()) {
		if (e->Value() == std::string("data"))
			pNodoDatos = e;
	}
	for (TiXmlElement* e = pElemento->FirstChildElement(); e != NULL;
		e->NextSiblingElement()) {
		TiXmlText* texto = e->ToText();
		std::string t = texto->Value();
		idDecodificados = base64_decode(t);
	}

	uLongf numGids = m_ancho * m_alto * sizeof(int);
	std::vector<unsigned> ids(numGids);
	uncompress((Bytef*)&ids[0],&numGids,(const Bytef*)idDecodificados.c_str(),
		idDecodificados.size());

	std::vector<int> filaCapa(m_ancho);

	for (int j = 0; j < m_alto; j++)
		datos.push_back(filaCapa);

	for (int filas = 0; filas < m_alto; filas++){
		for (int cols = 0; cols < m_ancho; cols++)
			datos[filas][cols] = ids[filas * m_ancho + cols];
	}

	pCapaPatron->setIdPatron(datos);
	pCapas->push_back(pCapaPatron);
}