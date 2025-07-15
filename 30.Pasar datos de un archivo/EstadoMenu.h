#pragma once
#ifndef __EstadoMenu__
#define __EstadoMenu__
#include "EstadoJuego.h"
#include <vector>
#include "ObjetoJuego.h"
#include "Juego.h"
#include "BotonMenu.h"

class EstadoMenu : public EstadoJuego
{
public:
	virtual void actualizar();
	virtual void renderizar();
	virtual bool enIngreso();
	virtual bool enSalida();
	virtual std::string getIdEstado() const;

private:
	static const std::string e_idmenu;
	std::vector<ObjetoJuego*> m_objetosJuego;
	static void e_menuParaJugar();
	static void e_salirDelMenu();
};

#endif // !__EstadoMenu__