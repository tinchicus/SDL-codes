#pragma once
#ifndef __CapaObjeto__
#define __CapaObjeto__

#include "Capa.h"
#include <vector>
#include "ObjetoJuego.h"

class CapaObjeto : public Capa
{
public:
	virtual void actualizar();
	virtual void renderizar();
	std::vector<ObjetoJuego*>* getObjetosJuego();

private:
	std::vector<ObjetoJuego*> m_objetosJuego;
};

#endif // !__CapaObjeto__