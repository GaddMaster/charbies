#include "Coordinates.h"



Coordinates::Coordinates()
{
}

Coordinates::~Coordinates()
{
}

Coordinates::Coordinates(int x, int y)
{
	m_y = y;
	m_x = x;
}

int Coordinates::get_x()
{
	return m_x;
}

int Coordinates::get_y()
{
	return m_y;
}
