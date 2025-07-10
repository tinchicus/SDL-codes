#pragma once
#ifndef __EstadoJugar__
#define __EstadoJugar__
#include "EstadoJuego.h"

class EstadoJugar : public EstadoJuego
{
public:
	virtual void actualizar();
	virtual void renderizar();
	virtual bool enIngreso();
	virtual bool enSalida();
	virtual std::string getIdEstado() const;

private:
	static const std::string e_idjugar;
};

#endif // !__EstadoJugar__