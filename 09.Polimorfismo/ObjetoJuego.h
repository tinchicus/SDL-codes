#pragma once
#ifndef __ObjetoJuego__
#define __ObjetoJuego__

#include <SDL3/SDL.h>
#include <string>
#include "ManejarTexturas.h"

class ObjetoJuego
{
public:
	virtual void cargar(float, float, float, float, std::string);
	virtual void dibujar(SDL_Renderer*);
	virtual void actualizar();
	virtual void limpiar();

protected:
	std::string m_idTextura;
	int m_frameActual;
	int m_filaActual;
	float m_x;
	float m_y;
	float m_ancho;
	float m_alto;
};

#endif //! defined(__ObjetoJuego__)