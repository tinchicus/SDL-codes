#include "ManejarSonido.h"

ManejarSonido* ManejarSonido::e_pInstanciar;

ManejarSonido* ManejarSonido::instanciar() {
	if (e_pInstanciar == 0) {
		e_pInstanciar = new ManejarSonido();
		return e_pInstanciar;
	}
	return e_pInstanciar;
}

ManejarSonido::ManejarSonido() {
	m_espec.format = SDL_AUDIO_F32;
	m_espec.freq = 44100;
	m_espec.channels = 2;
	if (!MIX_Init()) {
		std::cout << "Algo fallo" << SDL_GetError() << std::endl;
	}
	else {
		m_mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &m_espec);
	}
}
ManejarSonido::ManejarSonido(const ManejarSonido& sonido) {}
ManejarSonido::~ManejarSonido() {
	MIX_DestroyMixer(m_mixer);
}

bool ManejarSonido::carga(std::string archivo, std::string id, tipo_sonido tipo) {

	if (tipo == MUSICA) {
		MIX_Audio* pMusica = MIX_LoadAudio(m_mixer, archivo.c_str(), true);
		if (pMusica == 0) {
			std::cout << "No se pudo cargar Musica: ";
			std::cout << SDL_GetError() << std::endl;
			return false;
		}
		m_musica[id] = pMusica;
		return true;
	}
	else if (tipo == SFX) {
		MIX_Audio* pEfecto = MIX_LoadAudio(m_mixer, archivo.c_str(), true);
		if (pEfecto == 0) {
			std::cout << "No se pudo cargar SFX: ";
			std::cout << SDL_GetError() << std::endl;
			return false;
		}
		m_sfxs[id] = pEfecto;
		return true;
	}
	return false;
}

void ManejarSonido::playMusica(std::string id, int bucle) {
	SDL_PropertiesID props = SDL_CreateProperties();
	MIX_Track* track = MIX_CreateTrack(m_mixer);
	MIX_SetTrackAudio(track, m_musica[id]);
	
	SDL_SetNumberProperty(props,MIX_PROP_PLAY_LOOPS_NUMBER, bucle);
	MIX_PlayTrack(track, props);
}
void ManejarSonido::playSonido(std::string id, int bucle) {
	MIX_PlayAudio(m_mixer, m_sfxs[id]);
}