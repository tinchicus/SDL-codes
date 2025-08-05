#pragma once
#ifndef __GraficosAnimados__
#define __GraficosAnimados__
#include <SDL3/SDL.h>
#include "CargadorParams.h"
#include "SDLObjetoJuego.h"
#include "FabricaObjetosJuego.h"

class GraficosAnimados : public SDLObjetoJuego
{
public:
	GraficosAnimados();
	void actualizar();
	void cargar(const CargadorParams*);

private:
	int m_velocAnim;
	int m_numFrames;
};

class CreadorGraficoAnimado : public CreadorBase
{
public:
	ObjetoJuego* crearObjetoJuego() const;
};

#endif // !__GraficosAnimados__