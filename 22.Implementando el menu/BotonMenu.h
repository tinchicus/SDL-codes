#pragma once
#ifndef __BotonMenu__
#define __BotonMenu__
#include "SDLObjetoJuego.h"
#include "ManejarEntradas.h"
#include "CargadorParams.h"

class BotonMenu : public SDLObjetoJuego
{
public:
	BotonMenu(const CargadorParams*);
	virtual void dibujar();
	virtual void actualizar();
	virtual void limpiar();

private:
	enum estado_boton {
		MOUSE_FUERA = 0,
		MOUSE_SOBRE = 1,
		CLICKEADO = 2
	};
};

#endif // !__BotonMenu__