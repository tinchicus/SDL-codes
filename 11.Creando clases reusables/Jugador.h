#pragma once
#ifndef __Jugador__
#define __Jugador__

#include "SDLObjetoJuego.h"
#include "CargadorParams.h"

class Jugador : public SDLObjetoJuego
{
public:
	Jugador(const CargadorParams*);
	void dibujar();
	void actualizar();
	void limpiar();
};

#endif /* defined(__Jugador__)*/