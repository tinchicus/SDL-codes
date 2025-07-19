#pragma once
#ifndef __Juego__
#define __Juego__

#include <SDL3/SDL.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>
#include "ManejarTexturas.h"
#include "Jugador.h"
#include "Enemigo.h"
#include "ManejarEntradas.h"
#include <vector>
#include "MaquinaEstadoJuego.h"
#include "EstadoMenuPpal.h"
#include "EstadoJugar.h"
#include "FabricaObjetosJuego.h"

class Juego
{
public:
	~Juego() {}
	bool iniciar(const char*, int, int, bool);
	void renderizar();
	void actualizar();
	void manejaEventos();
	void limpiar();
	bool corriendo();
	static Juego* instanciar();
	SDL_Renderer* getRenderer() const;
	MaquinaEstadoJuego* getEstadoMaquina();

private:
	Juego();
	static Juego* e_pInstanciar;
	SDL_Window* m_pVentana;
	SDL_Renderer* m_pRenderer;
	bool m_bCorriendo;
	int m_frameActual;
	std::vector<ObjetoJuego*> m_objetosJuego;
	MaquinaEstadoJuego* m_pMaquinaEstadoJuego;
};

#endif /* defined(__Juego__) */

typedef Juego Eljuego;