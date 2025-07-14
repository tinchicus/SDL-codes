#include "CargadorParams.h"

CargadorParams::CargadorParams(float x, float y,
	float ancho, float alto, std::string id) :
	m_x(x), m_y(y), m_ancho(ancho), m_alto(alto), m_idTextura(id) {
}

float CargadorParams::getX() const { return m_x; }
float CargadorParams::getY() const { return m_y; }
float CargadorParams::getAncho() const { return m_ancho; }
float CargadorParams::getAlto() const { return m_alto; }

std::string CargadorParams::getIdTextura() const { return m_idTextura; }