#pragma once
#ifndef __EstadoJugar__
#define __EstadoJugar__
#include "EstadoJuego.h"
#include <vector>
#include "ObjetoJuego.h"
#include "ManejarTexturas.h"
#include "Juego.h"
#include "EstadoPausa.h"
#include "EstadoFinal.h"
#include "ParserNivel.h"

class EstadoJugar : public EstadoJuego
{
public:
	virtual void actualizar();
	virtual void renderizar();
	virtual bool enIngreso();
	virtual bool enSalida();
	virtual std::string getIdEstado() const;
	bool chekaColision(SDLObjetoJuego*, SDLObjetoJuego*);

private:
	static const std::string e_idjugar;
	std::vector<ObjetoJuego*> m_objetosJuego;
	Nivel* pNivel;
};

#endif // !__EstadoJugar__