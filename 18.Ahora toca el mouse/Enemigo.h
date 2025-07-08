#pragma once
#ifndef __Enemigo__
#define __Enemigo__
#include "SDLObjetoJuego.h"
#include "CargadorParams.h"

class Enemigo : public SDLObjetoJuego
{
public:
	Enemigo(const CargadorParams*);
	void dibujar();
	void actualizar();
	void limpiar();
};

#endif // !__Enemigo__