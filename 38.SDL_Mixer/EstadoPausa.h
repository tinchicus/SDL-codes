#pragma once
#ifndef __EstadoPausa__
#define __EstadoPausa__
#include "EstadoJuego.h"
#include "ObjetoJuego.h"
#include "ManejarTexturas.h"
#include <vector>
#include "Juego.h"

class EstadoPausa : public EstadoMenu
{
public:
	virtual void actualizar();
	virtual void renderizar();
	virtual bool enIngreso();
	virtual bool enSalida();
	virtual std::string getIdEstado() const;

private:
	static void e_volverMenu();
	static void e_retomarJuego();
	static const std::string e_idpausa;
	std::vector<ObjetoJuego*> m_objetosJuego;
	virtual void setCallbacks(const std::vector<Callback>&);
};

#endif // !__EstadoPausa__