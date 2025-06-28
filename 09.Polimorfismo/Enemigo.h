#pragma once
#ifndef __Enemigo__
#define __Enemigo__
#include "ObjetoJuego.h"

class Enemigo : public ObjetoJuego
{
public:
	void cargar(float, float, float, float, std::string);
	void dibujar(SDL_Renderer*);
	void actualizar();
	void limpiar();
};

#endif // !__Enemigo__