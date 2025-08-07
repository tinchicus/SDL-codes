#pragma once
#ifndef __BotonMenu__
#define __BotonMenu__
#include "SDLObjetoJuego.h"
#include "ManejarEntradas.h"
#include "CargadorParams.h"
#include "FabricaObjetosJuego.h"

class BotonMenu : public SDLObjetoJuego
{
public:
	// BotonMenu(const CargadorParams*, void (*)());
	BotonMenu();
	virtual void dibujar();
	virtual void actualizar();
	virtual void limpiar();
	void cargar(const CargadorParams*);
	void setCallback(void(*)());
	int getCallbackId();

private:
	enum estado_boton {
		MOUSE_FUERA = 0,
		MOUSE_SOBRE = 1,
		CLICKEADO = 2
	};
	void (*m_callback)();
	bool m_bLiberado;
	int m_idcallback;
};

class CreadorBotonMenu : public CreadorBase
{
public:
	ObjetoJuego* crearObjetoJuego() const;
};

#endif // !__BotonMenu__