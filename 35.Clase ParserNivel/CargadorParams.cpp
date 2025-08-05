#include "CargadorParams.h"

CargadorParams::CargadorParams(float x, float y,
	float ancho, float alto, std::string id, int numFrames,
	int idCallback, int velocAnim) :
	m_x(x), m_y(y), m_ancho(ancho), m_alto(alto),
	m_idTextura(id), m_numFrames(numFrames),
	m_idCallback(idCallback), m_velocAnim(velocAnim) {
}

float CargadorParams::getX() const { return m_x; }
float CargadorParams::getY() const { return m_y; }
float CargadorParams::getAncho() const { return m_ancho; }
float CargadorParams::getAlto() const { return m_alto; }
int CargadorParams::getNumFrames() const { return m_numFrames; }
int CargadorParams::getIdcallback() const { return m_idCallback; }
int CargadorParams::getVelocAnim() const { return m_velocAnim; }

std::string CargadorParams::getIdTextura() const { return m_idTextura; }