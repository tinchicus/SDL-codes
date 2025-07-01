#include "Juego.h"
#include <iostream>

int main(int argc, char* argv[]) {
	std::cout << "Iniciando el juego..." << std::endl;
	if (Eljuego::instanciar()->iniciar("Capitulo 1", 640, 480, false)) {
		std::cout << "Inicio Exitoso" << std::endl;
		while (Eljuego::instanciar()->corriendo()) {
			Eljuego::instanciar()->manejaEventos();
			Eljuego::instanciar()->actualizar();
			Eljuego::instanciar()->renderizar();
			SDL_Delay(10);
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