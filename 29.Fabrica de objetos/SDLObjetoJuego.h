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
	SDLObjetoJuego();
	virtual void dibujar();
	virtual void actualizar();
	virtual void limpiar();
	Vector2D& getPosicion();
	float getAncho();
	float getAlto();
	virtual void cargar(const CargadorParams*);

protected:
	float m_ancho;
	float m_alto;
	int m_filaActual;
	int m_frameActual;
	std::string m_idTextura;
	Vector2D m_posicion;
	Vector2D m_velocidad;
	Vector2D m_aceleracion;
	int m_numFrames;
};

#endif // !__SDLObjetoJuego__