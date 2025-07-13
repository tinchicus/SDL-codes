#pragma once
#ifndef __EstadoJugar__
#define __EstadoJugar__
#include "EstadoJuego.h"
#include <vector>
#include "ObjetoJuego.h"
#include "ManejarTexturas.h"
#include "Juego.h"
#include "EstadoPausa.h"

class EstadoJugar : public EstadoJuego
{
public:
	virtual void actualizar();
	virtual void renderizar();
	virtual bool enIngreso();
	virtual bool enSalida();
	virtual std::string getIdEstado() const;

private:
	static const std::string e_idjugar;
	std::vector<ObjetoJuego*> m_objetosJuego;
};

#endif // !__EstadoJugar__