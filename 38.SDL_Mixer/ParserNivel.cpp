#include "ParserNivel.h"
#include <Windows.h>

Nivel* ParserNivel::parseNivel(const char* archivo) {
	TiXmlDocument nivelDocumento;
	nivelDocumento.LoadFile(archivo);

	Nivel* pNivel = new Nivel();

	TiXmlElement* pRaiz = nivelDocumento.RootElement();

	pRaiz->Attribute("tilewidth", &m_tamPatron);
	pRaiz->Attribute("width", &m_ancho);
	pRaiz->Attribute("height", &m_alto);

	TiXmlElement* pPropiedades = pRaiz->FirstChildElement();

	for (TiXmlElement* e = pPropiedades->FirstChildElement(); e != NULL;
		e = e->NextSiblingElement()) {
		if (e->Value() == std::string("property"))
			parseTexturas(e);
	}

	for (TiXmlElement* e = pRaiz->FirstChildElement(); e != NULL;
		e = e->NextSiblingElement()) {
		if (e->Value() == std::string("tileset")) {
			parseConjuntos(e, pNivel->getConjPatron());
		}
	}

	for (TiXmlElement* e = pRaiz->FirstChildElement(); e != NULL;
		e = e->NextSiblingElement()) {
		if (e->Value() == std::string("objectgroup") ||
			e->Value() == std::string("layer")) {
			if (e->FirstChildElement()->Value() == std::string("object"))
			{
				parseCapaObjeto(e, pNivel->getCapas());
			}
			else if (e->FirstChildElement()->Value() == std::string("data")) {
				parseCapaPatron(e, pNivel->getCapas(), pNivel->getConjPatron());
			}
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
	pRaizConjuntos->FirstChildElement()->Attribute("width", &conjunto.ancho);
	pRaizConjuntos->FirstChildElement()->Attribute("height", &conjunto.alto);
	pRaizConjuntos->Attribute("firstgid", &conjunto.primerCuadric);
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

	TiXmlElement* pNodoDatos = NULL;

	for (TiXmlElement* e = pElemento->FirstChildElement(); e != NULL;
		e = e->NextSiblingElement()) {
		if (e->Value() == std::string("data"))
			pNodoDatos = e;
	}
	for (TiXmlNode* e = pNodoDatos->FirstChild(); e != NULL;
		e = e->NextSibling()) {
		TiXmlText* texto = e->ToText();
		std::string t = texto->Value();
		idDecodificados = base64_decode(t);
	}

	uLongf tamIds = m_ancho * m_alto * sizeof(int);
	std::vector<int> ids(m_ancho * m_alto);
	uncompress((Bytef*)&ids[0], &tamIds, (const Bytef*)idDecodificados.c_str(),
		idDecodificados.size());

	std::vector<int> filaCapa(m_ancho);

	for (int j = 0; j < m_alto; j++)
		datos.push_back(filaCapa);

	for (int filas = 0; filas < m_alto; filas++) {
		for (int cols = 0; cols < m_ancho; cols++)
			datos[filas][cols] = ids[filas * m_ancho + cols];
	}

	pCapaPatron->setIdPatron(datos);
	pCapas->push_back(pCapaPatron);
}

void ParserNivel::parseTexturas(TiXmlElement* pRaizTextura) {
	Elmanejador::instanciar()->cargar(pRaizTextura->Attribute("value"), 
		pRaizTextura->Attribute("name"),
		Eljuego::instanciar()->getRenderer());
}

void ParserNivel::parseCapaObjeto(TiXmlElement* pElementoObj, 
	std::vector<Capa*>* pCapas) {
	CapaObjeto* pCapaObjeto = new CapaObjeto();

	OutputDebugStringA(pElementoObj->FirstChildElement()->Value());

	for (TiXmlElement* e = pElementoObj->FirstChildElement(); e != NULL;
		e=e->NextSiblingElement()) {
		OutputDebugStringA(e->Value());
		if (e->Value() == std::string("object")) {
			int x, y, ancho, alto, numFrames, idCallback = 0, velocAnim = 0;
			std::string idTextura;
			e->Attribute("x", &x);
			e->Attribute("y", &y);
			ObjetoJuego* pObjetoJuego = Elfabricante::instanciar()->
				crear(e->Attribute("type"));
			for (TiXmlElement* propiedades = e->FirstChildElement(); 
				propiedades != NULL;
				propiedades = propiedades->NextSiblingElement()) {
				if (propiedades->Value() == std::string("properties")) {
					for(TiXmlElement* propiedad=propiedades->FirstChildElement();
						propiedad!=NULL;
						propiedad=propiedad->NextSiblingElement()) {
						if (propiedad->Value() == std::string("property")) {
							if (propiedad->Attribute("name") == std::string("numFrames")) {
								propiedad->Attribute("value", &numFrames);
							}
							else if (propiedad->Attribute("name") == std::string("altoTextura")) {
								propiedad->Attribute("value", &alto);
							}
							else if (propiedad->Attribute("name") == std::string("anchoTextura")) {
								propiedad->Attribute("value", &ancho);
							}
							else if (propiedad->Attribute("name") == std::string("idTextura")) {
								idTextura = propiedad->Attribute("value");
							}
							else if (propiedad->Attribute("name") == std::string("idCallback")) {
								propiedad->Attribute("value", &idCallback);
							}
							else if (propiedad->Attribute("name") == std::string("velocAnim")) {
								propiedad->Attribute("value", &velocAnim);
							}
						}
					}
				}
			}
			pObjetoJuego->cargar(new CargadorParams(x,y,ancho,alto,idTextura,
				numFrames,idCallback,velocAnim));
			pCapaObjeto->getObjetosJuego()->push_back(pObjetoJuego);
		}
	}
	pCapas->push_back(pCapaObjeto);
}