#include "EstadoParser.h"

bool EstadoParser::estadoParse(const char* estadoArchivo,
	std::string idEstado, std::vector<ObjetoJuego*>* pObjetos,
	std::vector<std::string>* pIdtexturas) {
	TiXmlDocument xmlDoc;
	if (!xmlDoc.LoadFile(estadoArchivo)) {
		std::cerr << xmlDoc.ErrorDesc() << std::endl;
		return false;
	}
	TiXmlElement* pRaiz = xmlDoc.RootElement();
	TiXmlElement* pEstadoRaiz = 0;
	for (TiXmlElement* e = pRaiz->FirstChildElement(); e != NULL;
		e = e->NextSiblingElement()) {
		if (e->Value() == idEstado)
			pEstadoRaiz = e;
	}
	TiXmlElement* pTexturaRaiz = 0;
	for (TiXmlElement* e = pEstadoRaiz->FirstChildElement(); e != NULL;
		e = e->NextSiblingElement()) {
		if (e->Value() == std::string("texturas"))
			pTexturaRaiz = e;
	}
	texturasParse(pTexturaRaiz, pIdtexturas);
	TiXmlElement* pObjetoRaiz = 0;
	for (TiXmlElement* e = pEstadoRaiz->FirstChildElement(); e != NULL;
		e = e->NextSiblingElement()) {
		if (e->Value() == std::string("objetos"))
			pObjetoRaiz = e;
	}
	objetosParse(pObjetoRaiz, pObjetos);

	return true;
}

void EstadoParser::texturasParse(TiXmlElement* pEstadoRaiz,
	std::vector<std::string>* pIdtexturas) {
	for (TiXmlElement* e = pEstadoRaiz->FirstChildElement(); e != NULL;
		e = e->NextSiblingElement()) {
		std::string atNombreArch = e->Attribute("archivo");
		std::string idAtributo = e->Attribute("id");
		pIdtexturas->push_back(idAtributo);
		Elmanejador::instanciar()->cargar(atNombreArch, idAtributo,
			Eljuego::instanciar()->getRenderer());
	}
}

void EstadoParser::objetosParse(TiXmlElement* pEstadoRaiz,
	std::vector<ObjetoJuego*>* pObjetos) {
	for (TiXmlElement* e = pEstadoRaiz->FirstChildElement(); e != NULL;
		e = e->NextSiblingElement()) {
		int x, y, ancho, alto, numFrames, idCallback, velocAnim;
		std::string idTextura;
		e->Attribute("x", &x);
		e->Attribute("y", &y);
		e->Attribute("ancho", &ancho);
		e->Attribute("alto", &alto);
		e->Attribute("numFrames", &numFrames);
		e->Attribute("idCallback", &idCallback);
		e->Attribute("velocAnim", &velocAnim);
		idTextura = e->Attribute("idTextura");
		ObjetoJuego* pObjetoJuego = Elfabricante::instanciar()->
			crear(e->Attribute("tipo"));
		pObjetoJuego->cargar(new CargadorParams(x, y, ancho, alto,
			idTextura, numFrames, idCallback, velocAnim));
		pObjetos->push_back(pObjetoJuego);
	}
}