#pragma once
#ifndef __ManejarEntradas__
#define __ManejarEntradas__
#include <SDL3/SDL.h>
#include <SDL3/SDL_joystick.h>
#include <vector>
#include "Juego.h"
#include "Vector2D.h"

enum botones_mouse {
	IZQUIERDO = 0,
	MEDIO = 1,
	DERECHO = 2
};

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
	bool getEstadoBotonMouse(int);
	Vector2D* getPosicionMouse();
	bool teclaPresionada(SDL_Scancode);
	void enTeclaAbajo();
	void enTeclaArriba();
	void enMoverMouse(SDL_Event&);
	void enBotonMouseAbajo(SDL_Event&);
	void enBotonMouseArriba(SDL_Event&);
	void resetear();
	void enJoyMoverEje(SDL_Event&);
	void enBotonJoyAbajo(SDL_Event&);
	void enBotonJoyArriba(SDL_Event&);
	int obtenerJoystick(SDL_Event&);

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
	std::vector<bool> m_estadoBotonMouse;
	Vector2D* m_posicionMouse;
	const bool* m_estadoTecla = SDL_GetKeyboardState(0);
};

#endif // !__ManejarEntradas__

typedef ManejarEntradas Controles;