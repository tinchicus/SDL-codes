#pragma once
#ifndef __ObjetoJuego__
#define __ObjetoJuego__

#include <SDL3/SDL.h>
#include <string>
#include "ManejarTexturas.h"
#include "CargadorParams.h"

class ObjetoJuego
{
public:
	virtual void dibujar() = 0;
	virtual void actualizar() = 0;
	virtual void limpiar() = 0;

protected:
	ObjetoJuego(const CargadorParams*);
	virtual ~ObjetoJuego();
};

#endif //! defined(__ObjetoJuego__)