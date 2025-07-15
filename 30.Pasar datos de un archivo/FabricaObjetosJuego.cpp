#include "FabricaObjetosJuego.h"
#include <Windows.h>

CreadorBase::~CreadorBase() {}

bool FabricaObjetosJuego::registrarTipo(std::string id, CreadorBase* pCreador) {
	std::map<std::string, CreadorBase*>::iterator it = m_creadores.find(id);
	if (it != m_creadores.end()) {
		delete pCreador;
		return false;
	}
	m_creadores[id] = pCreador;
	return true;
}

ObjetoJuego* FabricaObjetosJuego::crear(std::string id) {
	std::map<std::string, CreadorBase*>::iterator it = m_creadores.find(id);
	if (it == m_creadores.end()) {
		char bufmsj[200] = "";
		sprintf_s(bufmsj, "No se encontro el tipo: %d\n", id);
		OutputDebugStringA(bufmsj);
		return NULL;
	}
	CreadorBase* pCreador = (*it).second;
	return pCreador->crearObjetoJuego();
}

FabricaObjetosJuego* FabricaObjetosJuego::e_pInstancia = 0;
FabricaObjetosJuego::FabricaObjetosJuego() {}
FabricaObjetosJuego::~FabricaObjetosJuego() {}
FabricaObjetosJuego* FabricaObjetosJuego:: instanciar() {
	if (e_pInstancia == 0)
		e_pInstancia = new FabricaObjetosJuego();

	return e_pInstancia;
}