#pragma once
#ifndef __ManejarEntradas__
#define __ManejarEntradas__
#include <SDL3/SDL.h>
#include <SDL3/SDL_joystick.h>
#include <vector>
#include "Juego.h"
#include "Vector2D.h"

class ManejarEntradas
{
public:
	static ManejarEntradas* instanciar();
	void actualizar();
	void limpiar();
	void iniciarJoysticks();
	bool joysticksIniciados();
	int valorX(int, int);
	int valorY(int, int);
	bool getEstadoBoton(int, int);

private:
	ManejarEntradas();
	~ManejarEntradas();
	static ManejarEntradas* e_pInstancia;
	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoyIniciados;
	int total_joy;
	SDL_JoystickID* joysticks;
	std::vector<std::pair<Vector2D*, Vector2D*>> m_valoresJoystick;
	const int m_joystickZonaMuerta = 10000;
	std::vector<std::vector<bool>> m_estadoBoton;
};

#endif // !__ManejarEntradas__

typedef ManejarEntradas Controles;