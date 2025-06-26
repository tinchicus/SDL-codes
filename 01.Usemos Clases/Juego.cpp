#include "Juego.h"
#include <Windows.h>

bool Juego::iniciar(const char* titulo, int ancho, int alto, int flags) {
    if (SDL_Init(SDL_INIT_EVENTS) != 0) {
        OutputDebugStringA("SDL_Init iniciado\n");
        m_pVentana = SDL_CreateWindow(titulo, ancho, alto, flags);

        if (m_pVentana != 0) {
            OutputDebugStringA("Ventana Creada\n");
            m_pRenderer = SDL_CreateRenderer(m_pVentana, NULL);
            if (m_pRenderer != 0) {
                OutputDebugStringA("Render Exitoso\n");
                SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
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
    return true;
}

void Juego::renderizar() {
    SDL_RenderClear(m_pRenderer);
    SDL_RenderPresent(m_pRenderer);
}

void Juego::manejaEventos() {
    SDL_Event evento;
    if (SDL_PollEvent(&evento)) {
        switch (evento.type) {
        case SDL_EVENT_QUIT:
            m_bCorriendo = false;
            break;
        default:
            break;
        }
    }
}

void Juego::actualizar() {}

void Juego::limpiar() {
    OutputDebugStringA("Limpiando Memoria\n");
    SDL_DestroyWindow(m_pVentana);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

bool Juego::corriendo() { return m_bCorriendo; }