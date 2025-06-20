#include "Juego.h"
#include <Windows.h>

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
    const char* mensaje = "Hola Mundo!";
    const float scale = 4.0f;
    int w = 0, h = 0;
    float x, y;

    SDL_GetRenderOutputSize(m_pRenderer, &w, &h);
    SDL_SetRenderScale(m_pRenderer, scale, scale);
    x = ((w / scale) - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * SDL_strlen(mensaje)) / 2;
    y = ((h / scale) - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE) / 2;

    SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(m_pRenderer);
    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
    SDL_RenderDebugText(m_pRenderer, x, y, mensaje);
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

void Juego::limpiar() {
    OutputDebugStringA("Limpiando Memoria\n");
    SDL_DestroyWindow(m_pVentana);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}