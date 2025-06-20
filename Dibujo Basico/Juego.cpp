#include "Juego.h"
#include <Windows.h>

bool Juego::iniciar(const char* titulo, int ancho, int alto, bool pantallaCompleta) {
    int flags = 0;
    float w,h;
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

    SDL_Surface* iSurfaceTemp = SDL_LoadBMP("assets/rider.bmp");
    m_pTextura = SDL_CreateTextureFromSurface(
        m_pRenderer,
        iSurfaceTemp);
    SDL_DestroySurface(iSurfaceTemp);
    SDL_GetTextureProperties(m_pTextura);
    SDL_GetTextureSize(m_pTextura, &w, &h);
    m_destinoRectangulo.x = m_origenRectangulo.x = 0;
    m_destinoRectangulo.y = m_origenRectangulo.y = 0;
    m_destinoRectangulo.w = m_origenRectangulo.w = w;
    m_destinoRectangulo.h = m_origenRectangulo.h = h;

    return true;
}

void Juego::renderizar() {
    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(m_pRenderer);
    SDL_RenderTexture(m_pRenderer, m_pTextura, &m_origenRectangulo, 
        &m_destinoRectangulo);
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

void Juego::actualizar(){}

void Juego::limpiar() {
    OutputDebugStringA("Limpiando Memoria\n");
    SDL_DestroyWindow(m_pVentana);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}