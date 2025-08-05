#pragma once
#ifndef __CapaPatron__
#define __CapaPatron__

#include "Capa.h"
#include <vector>
#include "Nivel.h"
#include "Vector2D.h"

class CapaPatron : public Capa
{
public:
	CapaPatron(int, const std::vector<ConjuntoPatron>&);
	virtual void actualizar();
	virtual void renderizar();
	void setIdPatron(const std::vector<std::vector<int>>&);
	void setTamPatron(int);
	ConjuntoPatron getConjuntoPorId(int);

private:
	int m_numColumnas;
	int m_numFilas;
	int m_tamPatron;
	Vector2D m_posicion;
	Vector2D m_velocidad;
	const std::vector<ConjuntoPatron>& m_conjuntos;
	std::vector<std::vector<int>> m_idPatron;
};

#endif // !__CapaPatron__