#include "ManejarTexturas.h"

bool ManejarTexturas::cargar(std::string nombreArchivo, std::string id,
	SDL_Renderer* pRenderer) {

	SDL_Surface* pSurfaceTemp = IMG_Load(nombreArchivo.c_str());
	if (pSurfaceTemp == 0) return false;

	SDL_Texture* pTextura = SDL_CreateTextureFromSurface(pRenderer, 
		pSurfaceTemp);
	SDL_DestroySurface(pSurfaceTemp);

	if (pTextura != 0) {
		m_mapaTextura[id] = pTextura;
		return true;
	}

	return false;
}

void ManejarTexturas::dibujar(std::string id, float x, float y, 
	float ancho, float alto,
	SDL_Renderer* pRenderer, SDL_FlipMode inverso) {

	SDL_FRect orgRect;
	SDL_FRect dstRect;

	orgRect.x = 0;
	orgRect.y = 0;
	orgRect.w = dstRect.w = ancho;
	orgRect.h = dstRect.h = alto;
	dstRect.x = x;
	dstRect.y = y;

	SDL_RenderTextureRotated(pRenderer, m_mapaTextura[id], 
		&orgRect, &dstRect,
		0,0,inverso);
}

void ManejarTexturas::dibujar_frame(std::string id, float x, float y, 
	float ancho, float alto,
	int lineaActual, int frameActual,
	SDL_Renderer* pRenderer, SDL_FlipMode inverso) {

	SDL_FRect orgRect;
	SDL_FRect dstRect;

	orgRect.x = ancho * frameActual;
	orgRect.y = alto * (lineaActual - 1);
	orgRect.w = dstRect.w = ancho;
	orgRect.h = dstRect.h = alto;
	dstRect.x = x;
	dstRect.y = y;

	SDL_RenderTextureRotated(pRenderer, m_mapaTextura[id],
		&orgRect, &dstRect,
		0, 0, inverso);
}