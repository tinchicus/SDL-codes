#pragma once
#ifndef __EstadoJuego__
#define __EstadoJuego__
#include <iostream>
#include <string>
#include <vector>

class EstadoJuego
{
public:
	virtual void actualizar() = 0;
	virtual void renderizar() = 0;
	virtual bool enIngreso() = 0;
	virtual bool enSalida() = 0;
	virtual std::string getIdEstado() const = 0;

protected:
	std::vector<std::string> m_listaIdtexturas;
};

#endif // !__EstadoJuego__