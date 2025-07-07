#include "Juego.h"
#include <iostream>

const int FPS = 60;
const int TIEMPO_DELAY = 1000.0f / FPS;

int main(int argc, char* argv[]) {
	Uint32 frame_inicio, tiempo_frame;
	std::cout << "Iniciando el juego..." << std::endl;
	if (Eljuego::instanciar()->iniciar("Capitulo 1", 640, 480, false)) {
		std::cout << "Inicio Exitoso" << std::endl;
		while (Eljuego::instanciar()->corriendo()) {
			frame_inicio = SDL_GetTicks();
			Eljuego::instanciar()->manejaEventos();
			Eljuego::instanciar()->actualizar();
			Eljuego::instanciar()->renderizar();
			tiempo_frame = SDL_GetTicks() - frame_inicio;
			if (tiempo_frame < TIEMPO_DELAY)
				SDL_Delay((int)(TIEMPO_DELAY - tiempo_frame));
		}
	}
	else {
		std::cout << "Fallo el inicio..." << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}

	std::cout << "Cerrando el juego..." << std::endl;
	Eljuego::instanciar()->limpiar();

	return 0;
}