#include "CapaPatron.h"

CapaPatron::CapaPatron(int tamPatron, const std::vector<ConjuntoPatron>& conjuntos) :
	m_tamPatron(tamPatron), m_conjuntos(conjuntos),
	m_posicion(0, 0), m_velocidad(0, 0) {
	m_numColumnas = (Eljuego::instanciar()->getAnchoJuego() / m_tamPatron);
	m_numFilas = (Eljuego::instanciar()->getAltoJuego() / m_tamPatron);
}

void CapaPatron::actualizar() {
	m_posicion += m_velocidad;
	m_velocidad.setX(1);
}

void CapaPatron::renderizar() {
	int x, y, x2, y2 = 0;
	x = m_posicion.getX() / m_tamPatron;
	y = m_posicion.getY() / m_tamPatron;
	x2 = int(m_posicion.getX()) % m_tamPatron;
	y2 = int(m_posicion.getY()) % m_tamPatron;
	for (int i = 0; i < m_numFilas; i++) {
		for (int j = 0; j < m_numColumnas; j++) {
			int id = m_idPatron[i][j + x];
			if (id == 0) continue;
			ConjuntoPatron conjuntos = getConjuntoPorId(id);
			id--;
			Elmanejador::instanciar()->dibujar_patron(conjuntos.nombre,
				conjuntos.margen, conjuntos.espaciado,
				(j * m_tamPatron) - x2, (i * m_tamPatron) - y2, m_tamPatron,
				m_tamPatron,
				(id - (conjuntos.primerCuadric - 1)) / conjuntos.numColumnas,
				(id - (conjuntos.primerCuadric - 1)) % conjuntos.numColumnas,
				Eljuego::instanciar()->getRenderer());
		}
	}
}

void CapaPatron::setIdPatron(const std::vector < std::vector<int>>& datos) {
	m_idPatron = datos;
}
void CapaPatron::setTamPatron(int tamPatron) {
	m_tamPatron = tamPatron;
}

ConjuntoPatron CapaPatron::getConjuntoPorId(int id) {
	for (int i = 0; i < m_conjuntos.size(); i++) {
		if (i + 1 <= m_conjuntos.size() - 1) {
			if (id >= m_conjuntos[i].primerCuadric &&
				id <= m_conjuntos[i + 1].primerCuadric) {
				return m_conjuntos[i];
			}
		}
		else {
			return m_conjuntos[i];
		}
	}

	std::cout << "No se encontro conjunto, devuelvo uno vacio\n";
	ConjuntoPatron c;
	return c;
}