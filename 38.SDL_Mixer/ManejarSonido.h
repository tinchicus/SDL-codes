#pragma once
#ifndef __ManejarSonido__
#define __ManejarSonido__
#include <SDL3_mixer/SDL_mixer.h>
#include <iostream>
#include <string>
#include <map>

enum tipo_sonido {
	MUSICA = 0,
	SFX = 1
};

class ManejarSonido
{
public:
	static ManejarSonido* instanciar();
	bool carga(std::string, std::string, tipo_sonido);
	void playSonido(std::string, int);
	void playMusica(std::string, int);

private:
	static ManejarSonido* e_pInstanciar;
	std::map<std::string, MIX_Audio*> m_sfxs;
	std::map<std::string, MIX_Audio*> m_musica;
	ManejarSonido();
	~ManejarSonido();
	ManejarSonido(const ManejarSonido&);
	ManejarSonido& operator=(const ManejarSonido&);
	MIX_Mixer* m_mixer;
	SDL_AudioSpec m_espec;

};

#endif // !__ManejarSonido__

typedef ManejarSonido Elsonido;