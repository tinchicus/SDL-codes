#pragma once
#ifndef __Jugador__
#define __Jugador__

#include "SDLObjetoJuego.h"
#include "CargadorParams.h"
#include "ManejarEntradas.h"
#include "FabricaObjetosJuego.h"

class Jugador : public SDLObjetoJuego
{
public:
	Jugador(const CargadorParams*);
	Jugador();
	void dibujar();
	void actualizar();
	void limpiar();
	void cargar(const CargadorParams*);

private:
	void manejaEntrada();
};

class CreadorJugador : public CreadorBase
{
public:
	ObjetoJuego* crearObjetoJuego() const;
};

#endif /* defined(__Jugador__)*/