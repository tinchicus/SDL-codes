#pragma once
#ifndef __Enemigo__
#define __Enemigo__
#include "SDLObjetoJuego.h"
#include "CargadorParams.h"
#include "FabricaObjetosJuego.h"

class Enemigo : public SDLObjetoJuego
{
public:
	Enemigo(const CargadorParams*);
	Enemigo();
	void dibujar();
	void actualizar();
	void limpiar();
	void cargar(const CargadorParams*);
};

class CreadorEnemigo : public CreadorBase
{
public:
	ObjetoJuego* crearObjetoJuego() const;
};

#endif // !__Enemigo__