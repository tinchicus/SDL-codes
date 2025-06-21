#pragma once
#ifndef __Juego__
#define __Juego__

#include <SDL3/SDL.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>
#include "ManejarTexturas.h"

class Juego
{
public:
	Juego(){ }
	~Juego(){}
	bool iniciar(const char*, int, int, bool);
	void renderizar();
	void actualizar();
	void manejaEventos();
	void limpiar();

	bool corriendo() { return m_bCorriendo; }

private:
	SDL_Window* m_pVentana;
	SDL_Renderer* m_pRenderer;
	bool m_bCorriendo;
};

#endif /* defined(__Juego__) */