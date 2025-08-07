#pragma once
#ifndef __EstadoMenuPpal__
#define __EstadoMenuPpal__
#include "EstadoMenu.h"
#include <string>
#include <vector>
#include "ObjetoJuego.h"
#include "Juego.h"
#include "BotonMenu.h"
#include "EstadoParser.h"

class EstadoMenuPpal : public EstadoMenu
{
public:
	virtual void actualizar();
	virtual void renderizar();
	virtual bool enIngreso();
	virtual bool enSalida();
	virtual std::string getIdEstado() const;

private:
	virtual void setCallbacks(const std::vector<Callback>&);
	static void e_menuParaJugar();
	static void e_salirDelMenu();
	static const std::string e_idmenu;
	std::vector<ObjetoJuego*> m_objetosJuego;
};

#endif // !__EstadoMenuPpal__