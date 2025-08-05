#pragma once
#ifndef __Capa__
#define __Capa__

class Capa
{
public:
	virtual void renderizar() = 0;
	virtual void actualizar() = 0;

protected:
	virtual ~Capa();
};

#endif // !__Capa__