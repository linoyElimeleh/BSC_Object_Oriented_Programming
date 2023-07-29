#include "Point.h"


Point::Point(double x, double y)
{
	this->mx = x;
	this->my = y;
	this->scaleX = 1;
	this->scaleY = 1;
}
double Point::getX() const
{
	return (this->mx * this->scaleX);
}
double Point::getY() const
{
	return (this->my * this->scaleY);
}
double Point::getScaleX() const
{
	return this->scaleX;
}
double Point::getScaleY() const
{
	return this->scaleY;
}

void Point::setX(double x)
{
	this->mx = x;
}
void Point::setY(double y)
{
	this->my = y;
}
void Point::setScaleX(double scaleX)
{
	this->scaleX = scaleX;
}
void Point::setScaleY(double scaleY)
{
	this->scaleY = scaleY;
}

