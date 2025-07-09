#pragma once
#ifndef __CargadorParams__
#define __CargadorParams__
#include <string>

class CargadorParams
{
public:
	CargadorParams(float, float, float, float, std::string);
	float getX() const;
	float getY() const;
	float getAncho() const;
	float getAlto() const;
	std::string getIdTextura() const;

private:
	float m_x;
	float m_y;
	float m_ancho;
	float m_alto;
	std::string m_idTextura;
};

#endif // !__CargadorParams__