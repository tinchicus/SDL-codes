#pragma once
#ifndef __FabricaObjetosJuego__
#define __FabricaObjetosJuego__
#include <string>
#include <map>
#include "ObjetoJuego.h"

class CreadorBase 
{
public:
	virtual ObjetoJuego* crearObjetoJuego() const = 0;
	virtual ~CreadorBase();
};

class FabricaObjetosJuego
{
public:
	bool registrarTipo(std::string, CreadorBase*);
	ObjetoJuego* crear(std::string);
	static FabricaObjetosJuego* instanciar();

private:
	std::map<std::string, CreadorBase*> m_creadores;
	FabricaObjetosJuego();
	~FabricaObjetosJuego();
	static FabricaObjetosJuego* e_pInstancia;
};

#endif // !__FabricaObjetosJuego__

typedef FabricaObjetosJuego Elfabricante;