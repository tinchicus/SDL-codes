#pragma once
#ifndef __Nivel__
#define __Nivel__
#include "Capa.h"
#include <string>
#include <vector>

struct ConjuntoPatron {
	int primerCuadric;
	int anchoPatron;
	int altoPatron;
	int espaciado;
	int margen;
	int ancho;
	int alto;
	int numColumnas;
	std::string nombre;
};

class Nivel
{
public:
	~Nivel();
	void actualizar();
	void renderizar();
	std::vector<ConjuntoPatron>* getConjPatron();
	std::vector<Capa*>* getCapas();

private:
	friend class ParserNivel;
	Nivel();
	std::vector<ConjuntoPatron> m_conjPatrones;
	std::vector<Capa*> m_capas;
};

#endif // !__Nivel__