#pragma once
#ifndef __ParserNivel__
#define __ParserNivel__
#include "tinyxml.h"
#include "Nivel.h"
#include "CapaPatron.h"
#include "ManejarTexturas.h"
#include "Juego.h"
#include "base64.h"
#include <zlib.h>

class ParserNivel
{
public:
	Nivel* parseNivel(const char* archivo);

private:
	void parseConjuntos(TiXmlElement*, std::vector<ConjuntoPatron>*);
	void parseCapaPatron(TiXmlElement*, std::vector<Capa*>*,
		const std::vector<ConjuntoPatron>*);
	int m_tamPatron;
	int m_ancho;
	int m_alto;
};

#endif // !__ParserNivel__