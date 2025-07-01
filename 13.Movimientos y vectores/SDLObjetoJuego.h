#pragma once
#ifndef __SDLObjetoJuego__
#define __SDLObjetoJuego__
#include <string>
#include "ObjetoJuego.h"
#include "CargadorParams.h"
#include "ManejarTexturas.h"
#include "Vector2D.h"

class SDLObjetoJuego : public ObjetoJuego
{
public:
	SDLObjetoJuego(const CargadorParams*);
	virtual void dibujar();
	virtual void actualizar();
	virtual void limpiar();

protected:
	//float m_x;
	//float m_y;
	float m_ancho;
	float m_alto;
	int m_filaActual;
	int m_frameActual;
	std::string m_idTextura;
	Vector2D m_posicion;
};

#endif // !__SDLObjetoJuego__