#pragma once
#ifndef __EstadoParser__
#define __EstadoParser__
#include <iostream>
#include <vector>
#include <string>
#include "tinyxml.h"
#include "ManejarTexturas.h"
#include "Juego.h"
#include "FabricaObjetosJuego.h"

class ObjetoJuego;

class EstadoParser
{
public:
	bool estadoParse(const char*, std::string, 
		std::vector<ObjetoJuego*>*, std::vector<std::string>*);

private:
	void objetosParse(TiXmlElement*, std::vector<ObjetoJuego*>*);
	void texturasParse(TiXmlElement*, std::vector<std::string>*);
};

#endif // !__EstadoParser__