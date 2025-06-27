#pragma once
#ifndef __Jugador__
#define __Jugador__

#include "ObjetoJuego.h"

class Jugador : public ObjetoJuego
{
public:
	void cargar(float, float, float, float, std::string);
	void dibujar(SDL_Renderer*);
	void actualizar();
	void limpiar();
};

#endif /* defined(__Jugador__)*/