#pragma once
#ifndef __Juego__
#define __Juego__

#include <SDL3/SDL.h>

class Juego
{
public:
	Juego() {}
	~Juego() {}
	bool iniciar(const char*, int, int, int);
	void renderizar();
	void actualizar();
	void manejaEventos();
	void limpiar();

	bool corriendo();

private:
	SDL_Window* m_pVentana;
	SDL_Renderer* m_pRenderer;
	bool m_bCorriendo;
};

#endif /* defined(__Juego__) */