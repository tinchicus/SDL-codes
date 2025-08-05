#pragma once
#ifndef __EstadoMenu__
#define __EstadoMenu__
#include "EstadoJuego.h"
#include <vector>
#include "ObjetoJuego.h"

class EstadoMenu : public EstadoJuego
{
protected:
	typedef void(*Callback)();
	virtual void setCallbacks(const std::vector<Callback>&) = 0;
	std::vector<Callback> m_callbacks;
};

#endif // !__EstadoMenu__