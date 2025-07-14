#pragma once
#ifndef __Jugador__
#define __Jugador__

#include "SDLObjetoJuego.h"
#include "CargadorParams.h"
#include "ManejarEntradas.h"
#include "FabricaObjetosJuego.h"

class CreadorJugador : public CreadorBase
{
public:
	ObjetoJuego* crearObjetoJuego() const;
};

class Jugador : public SDLObjetoJuego
{
public:
	Jugador();
	void dibujar();
	void actualizar();
	void limpiar();
	void cargar(const CargadorParams*);

private:
	void manejaEntrada();
};

#endif /* defined(__Jugador__)*/