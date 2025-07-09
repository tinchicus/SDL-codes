#pragma once
#ifndef __EstadoMenu__
#define __EstadoMenu__
#include "EstadoJuego.h"

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
};

#endif // !__EstadoMenu__