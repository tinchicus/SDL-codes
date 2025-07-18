#pragma once
#ifndef __CargadorParams__
#define __CargadorParams__
#include <string>

class CargadorParams
{
public:
	CargadorParams(float, float, float, float, std::string, int = 6, int = 0, int = 0);
	float getX() const;
	float getY() const;
	float getAncho() const;
	float getAlto() const;
	std::string getIdTextura() const;
	int getNumFrames() const;
	int getIdcallback() const;

private:
	float m_x;
	float m_y;
	float m_ancho;
	float m_alto;
	std::string m_idTextura;
	int m_numFrames;
	int m_idCallback;
	int m_velocAnim;
};

#endif // !__CargadorParams__