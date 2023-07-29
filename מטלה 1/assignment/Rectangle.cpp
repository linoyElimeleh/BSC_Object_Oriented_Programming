#include "Rectangle.h"

int Rectangle::m_count = 0;

Rectangle::Rectangle( double left, double top, double width, double height, int color )
{
	++m_count;
}