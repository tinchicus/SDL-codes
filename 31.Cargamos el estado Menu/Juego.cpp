#include "Juego.h"
#include <Windows.h>

Juego* Juego::e_pInstanciar = 0;

Juego* Juego::instanciar() {
    if (e_pInstanciar == 0) {
        e_pInstanciar = new Juego();
        return e_pInstanciar;
    }
    return e_pInstanciar;
}
Juego::Juego() {}

bool Juego::iniciar(const char* titulo, int ancho, int alto, bool pantallaCompleta) {
    int flags = 0;
    if (pantallaCompleta)
        flags = SDL_WINDOW_FULLSCREEN;

    if (SDL_Init(SDL_INIT_EVENTS) != 0) {
        OutputDebugStringA("SDL_Init iniciado\n");
        m_pVentana = SDL_CreateWindow(titulo, ancho, alto, flags);

        if (m_pVentana != 0) {
            OutputDebugStringA("Ventana Creada\n");
            m_pRenderer = SDL_CreateRenderer(m_pVentana, NULL);
            if (m_pRenderer != 0) {
                OutputDebugStringA("Render Exitoso\n");
                SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
            }
            else {
                OutputDebugStringA("Render Fallido\n");
                return false;
            }
        }
        else {
            OutputDebugStringA("Ventana no Creada\n");
            return false;
        }
    }
    else {
        OutputDebugStringA("Inicio Fallido\n");
        return false;
    }

    OutputDebugStringA("Inicio Exitoso\n");
    m_bCorriendo = true;

    if (!Elmanejador::instanciar()->cargar("assets/animate-alpha.png",
        "animado", m_pRenderer)) {
        return false;
    }

    m_objetosJuego.push_back(new Jugador(
        new CargadorParams(50, 100, 128, 82, "animado")));
    m_objetosJuego.push_back(new Enemigo(
        new CargadorParams(300, 300, 128, 82, "animado")));
    Controles::instanciar()->iniciarJoysticks();

    Elfabricante::instanciar()->registrarTipo("BotonMenu", new CreadorBotonMenu());

    m_pMaquinaEstadoJuego = new MaquinaEstadoJuego();
    m_pMaquinaEstadoJuego->cambiaEstado(new EstadoMenuPpal());

    return true;
}

void Juego::renderizar() {
    SDL_RenderClear(m_pRenderer);
    m_pMaquinaEstadoJuego->renderizar();
    SDL_RenderPresent(m_pRenderer);
    actualizar();
}

void Juego::manejaEventos() {
    Controles::instanciar()->actualizar();
    if (Controles::instanciar()->teclaPresionada(SDL_SCANCODE_RETURN)) {
        m_pMaquinaEstadoJuego->cambiaEstado(new EstadoJugar());
    }
}

void Juego::actualizar(){
    m_pMaquinaEstadoJuego->actualizar();
}

void Juego::limpiar() {
    OutputDebugStringA("Limpiando Memoria\n");
    SDL_DestroyWindow(m_pVentana);
    SDL_DestroyRenderer(m_pRenderer);
    Controles::instanciar()->limpiar();
    m_bCorriendo = false;
    SDL_Quit();
}

MaquinaEstadoJuego* Juego::getEstadoMaquina() {
    return m_pMaquinaEstadoJuego;
}

bool Juego::corriendo() { return m_bCorriendo; }

SDL_Renderer* Juego::getRenderer() const { return m_pRenderer; }