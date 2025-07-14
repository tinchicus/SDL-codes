#pragma once
#ifndef __GraficosAnimados__
#define __GraficosAnimados__
#include <SDL3/SDL.h>
#include "CargadorParams.h"
#include "SDLObjetoJuego.h"

class GraficosAnimados : public SDLObjetoJuego
{
public:
	GraficosAnimados(const CargadorParams*, int);
	void actualizar();

private:
	int m_velocAnim;
	int m_numFrames;
};

#endif // !__GraficosAnimados__