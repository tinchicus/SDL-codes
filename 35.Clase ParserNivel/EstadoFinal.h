#pragma once
#ifndef __EstadoFinal__
#define __EstadoFinal__
#include <string>
#include <vector>
#include "EstadoJuego.h"
#include "ObjetoJuego.h"
#include "Juego.h"
#include "BotonMenu.h"
#include "GraficosAnimados.h"

class EstadoFinal : public EstadoMenu
{
public:
	virtual void actualizar();
	virtual void renderizar();
	virtual bool enIngreso();
	virtual bool enSalida();
	virtual std::string getIdEstado() const;

private:
	static void e_volverMenu();
	static void e_reiniciar();
	static const std::string e_idfinal;
	std::vector<ObjetoJuego*> m_objetosJuego;
	virtual void setCallbacks(const std::vector<Callback>&);
};

#endif // !__EstadoFinal__