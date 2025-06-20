#include "Juego.h"
#include <Windows.h>

int m_frameActual;
ManejarTexturas m_manejarTexturas;

bool Juego::iniciar(const char* titulo, int ancho, int alto, bool pantallaCompleta) {
    int flags = 0;
    //float w,h;
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

    /* SDL_Surface* iSurfaceTemp = IMG_Load("assets/animate-alpha.png");
    m_pTextura = SDL_CreateTextureFromSurface(
        m_pRenderer,
        iSurfaceTemp);
    SDL_DestroySurface(iSurfaceTemp);
    SDL_GetTextureProperties(m_pTextura);
    SDL_GetTextureSize(m_pTextura, &w, &h);
    m_origenRectangulo.h = 82;
    m_origenRectangulo.w = 128;
    m_origenRectangulo.x = m_destinoRectangulo.x = 0;
    m_origenRectangulo.y = m_destinoRectangulo.y = 0;
    m_destinoRectangulo.w = m_origenRectangulo.w;
    m_destinoRectangulo.h = m_origenRectangulo.h; */

    m_manejarTexturas.cargar("assets/animate-alpha.png", "animado", m_pRenderer);

    return true;
}

void Juego::renderizar() {
    SDL_RenderClear(m_pRenderer);
    m_manejarTexturas.dibujar("animado", 0, 0, 128, 82, m_pRenderer);
    m_manejarTexturas.dibujar_frame("animado", 100, 100, 128, 82, 1, 
        m_frameActual, m_pRenderer);
    SDL_RenderPresent(m_pRenderer);
    actualizar();
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

void Juego::actualizar(){
    m_frameActual = int(((SDL_GetTicks() / 100) % 6));
}

void Juego::limpiar() {
    OutputDebugStringA("Limpiando Memoria\n");
    SDL_DestroyWindow(m_pVentana);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}