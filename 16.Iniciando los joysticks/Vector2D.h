#pragma once
#ifndef __Vector2D__
#define __Vector2D__
#include <math.h>
#include <iostream>

class Vector2D
{
public:
	Vector2D(float, float);
	float getX();
	float getY();
	void setX(float);
	void setY(float);
	float longitud();
	Vector2D operator+ (const Vector2D&) const;
	friend Vector2D& operator+= (Vector2D&, const Vector2D&);
	Vector2D operator- (const Vector2D&) const;
	friend Vector2D& operator-= (Vector2D&, const Vector2D&);
	Vector2D operator* (float);
	Vector2D& operator*= (float);
	Vector2D operator/ (float);
	Vector2D& operator/= (float);
	void normalizar();

private:
	float m_x;
	float m_y;
};

#endif // !__Vector2D__