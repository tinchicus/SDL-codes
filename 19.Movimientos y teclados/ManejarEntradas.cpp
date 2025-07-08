#include "ManejarEntradas.h"
#include <Windows.h>

ManejarEntradas* ManejarEntradas::e_pInstancia = 0;

ManejarEntradas* ManejarEntradas::instanciar() {
	if (e_pInstancia == 0)
		e_pInstancia = new ManejarEntradas();

	return e_pInstancia;
}

void ManejarEntradas::iniciarJoysticks() {
	if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);

	joysticks = SDL_GetJoysticks(&total_joy);

	if (total_joy > 0) {
		for (int i = 0; i < total_joy; i++) {
			SDL_Joystick* joy = SDL_OpenJoystick(joysticks[i]);
			if (joy) {
				m_joysticks.push_back(joy);
				m_valoresJoystick.push_back(std::make_pair(
					new Vector2D(0, 0), new Vector2D(0, 0)));
				std::vector<bool> tempBotones;
				for (int j = 0; j < SDL_GetNumJoystickButtons(joy);
					j++) {
					tempBotones.push_back(false);
				}
				m_estadoBoton.push_back(tempBotones);
			}
			else {
				OutputDebugStringA(SDL_GetError());
			}
		}
		SDL_SetJoystickEventsEnabled(true);
		m_bJoyIniciados = true;
		char bufmsj[200] = "";
		sprintf_s(bufmsj, "Joysticks Iniciados: %d\n", m_joysticks.size());
		OutputDebugStringA(bufmsj);
	}
	else {
		m_bJoyIniciados = false;
	}
}

bool ManejarEntradas::joysticksIniciados() {
	return m_bJoyIniciados;
}

void ManejarEntradas::limpiar() {
	if (m_bJoyIniciados) {
		for (unsigned int i = 0; i < total_joy; i++) {
			SDL_CloseJoystick(m_joysticks[i]);
		}
	}
}

void ManejarEntradas::actualizar() {
	SDL_Event evento;
	char bufmsj[200] = "";

	while (SDL_PollEvent(&evento)) {
		int joy_usando = 0;
		int cualEs = evento.jdevice.which;
		for (int i = 0; i < m_joysticks.size(); i++) {
			if (joysticks[i] == cualEs)
				joy_usando = i;
		}

		switch (evento.type) {
		case SDL_EVENT_QUIT:
			Eljuego::instanciar()->limpiar();
			break;

		case SDL_EVENT_JOYSTICK_AXIS_MOTION:
			switch (evento.jaxis.axis) {
			case 0:
				if (evento.jaxis.value > m_joystickZonaMuerta)
					m_valoresJoystick[joy_usando].first->setX(1);
				else if (evento.jaxis.value < -m_joystickZonaMuerta)
					m_valoresJoystick[joy_usando].first->setX(-1);
				else
					m_valoresJoystick[joy_usando].first->setX(0);
				break;

			case 1:
				if (evento.jaxis.value > m_joystickZonaMuerta)
					m_valoresJoystick[joy_usando].first->setY(1);
				else if (evento.jaxis.value < -m_joystickZonaMuerta)
					m_valoresJoystick[joy_usando].first->setY(-1);
				else
					m_valoresJoystick[joy_usando].first->setY(0);
				break;

			case 2:
				if (evento.jaxis.value > m_joystickZonaMuerta)
					m_valoresJoystick[joy_usando].second->setX(1);
				else if (evento.jaxis.value < -m_joystickZonaMuerta)
					m_valoresJoystick[joy_usando].second->setX(-1);
				else
					m_valoresJoystick[joy_usando].second->setX(0);
				break;

			case 3:
				if (evento.jaxis.value > m_joystickZonaMuerta)
					m_valoresJoystick[joy_usando].second->setY(1);
				else if (evento.jaxis.value < -m_joystickZonaMuerta)
					m_valoresJoystick[joy_usando].second->setY(-1);
				else
					m_valoresJoystick[joy_usando].second->setY(0);
				break;
			}
			break;

		case SDL_EVENT_JOYSTICK_BUTTON_DOWN:
			m_estadoBoton[joy_usando][evento.jbutton.button] = true;
			sprintf_s(bufmsj, "Boton presionado: %d\n",
				evento.jbutton.button);
			OutputDebugStringA(bufmsj);
			break;

		case SDL_EVENT_JOYSTICK_BUTTON_UP:
			m_estadoBoton[joy_usando][evento.jbutton.button] = false;
			break;

		case SDL_EVENT_MOUSE_BUTTON_DOWN:
			switch (evento.button.button) {
			case SDL_BUTTON_LEFT:
				m_estadoBotonMouse[IZQUIERDO] = true;
			case SDL_BUTTON_MIDDLE:
				m_estadoBotonMouse[MEDIO] = true;
			case SDL_BUTTON_RIGHT:
				m_estadoBotonMouse[DERECHO] = true;
			}
			break;

		case SDL_EVENT_MOUSE_BUTTON_UP:
			switch (evento.button.button) {
			case SDL_BUTTON_LEFT:
				m_estadoBotonMouse[IZQUIERDO] = false;
			case SDL_BUTTON_MIDDLE:
				m_estadoBotonMouse[MEDIO] = false;
			case SDL_BUTTON_RIGHT:
				m_estadoBotonMouse[DERECHO] = false;
			}
			break;

		case SDL_EVENT_MOUSE_MOTION:
			m_posicionMouse->setX(evento.motion.x);
			m_posicionMouse->setY(evento.motion.y);
			break;
		}
	}
}

int ManejarEntradas::valorX(int joy, int stick) {
	if (m_valoresJoystick.size() > 0) {
		if (stick == 1)
			return m_valoresJoystick[joy].first->getX();
		else if (stick == 2)
			return m_valoresJoystick[joy].second->getX();
	}
	return 0;
}

int ManejarEntradas::valorY(int joy, int stick) {
	if (m_valoresJoystick.size() > 0) {
		if (stick == 1)
			return m_valoresJoystick[joy].first->getY();
		else if (stick == 2)
			return m_valoresJoystick[joy].second->getY();
	}
	return 0;
}

bool ManejarEntradas::getEstadoBoton(int joy, int numBoton) {
	return m_estadoBoton[joy][numBoton];
}

bool ManejarEntradas::getEstadoBotonMouse(int numBoton) {
	return m_estadoBotonMouse[numBoton];
}

Vector2D* ManejarEntradas::getPosicionMouse() {
	return m_posicionMouse;
}

bool ManejarEntradas::teclaPresionada(SDL_Scancode tecla) {
	if (m_estadoTecla) {
		if (m_estadoTecla[tecla] == 1)
			return true;
		else
			return false;
	}
	return false;
}

ManejarEntradas::ManejarEntradas() {
	m_posicionMouse = new Vector2D(0, 0);
	for (int i = 0; i < 3; i++)
		m_estadoBotonMouse.push_back(false);
}

ManejarEntradas::~ManejarEntradas() {}