#pragma once
#ifndef __ManejarTexturas__
#define __ManejarTexturas__

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_image/SDL_image.h>
#include <string>
#include <map>

class ManejarTexturas
{
public:
	static ManejarTexturas* instanciar();
	bool cargar(std::string, std::string, SDL_Renderer*);
	void dibujar(std::string, float, float, float, float,
		SDL_Renderer*, SDL_FlipMode = SDL_FLIP_NONE);
	void dibujar_frame(std::string, float, float, float, float, int, int,
		SDL_Renderer*, SDL_FlipMode = SDL_FLIP_NONE);
	static ManejarTexturas* e_pInstancia;

private:
	ManejarTexturas();
	std::map<std::string, SDL_Texture*> m_mapaTextura;
};

#endif // !__ManejarTexturas__

typedef ManejarTexturas Elmanejador;