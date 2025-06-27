#include "Juego.h"

Juego* g_juego = 0;

int main(int argc, char* argv[]) {
	g_juego = new Juego();
	g_juego->iniciar("Juego", 640, 480, false);
	while (g_juego->corriendo()) {
		g_juego->manejaEventos();
		g_juego->renderizar();
	}
	g_juego->limpiar();
	return 0;
}