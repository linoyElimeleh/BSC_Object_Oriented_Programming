#include "Rectangle.h"
#include "Point.h"

int Rectangle::m_count = 0;

Rectangle::Rectangle(double left, double top, double width, double height, int color)
{
	this->left = left;
	this->top = top;
	this->width = width;
	this->height = height;
	topLeft = Point(left, top);
	bottomRight = Point(width - left, height - top);
	this->color = color;
	++m_count;
}

int Rectangle::getColor() const
{
	return this->color;
}
void Rectangle::setColor(int color)
{
	this->color = color;
}

Point& Rectangle::getTopLeftPoint()
{
	return this->topLeft;
}
Point& Rectangle::getBottomRightPoint()
{
	return this->bottomRight;
}

bool  Rectangle::contains(const Point& p)
{
	if (p.getX() < this->left || p.getX() > this->bottomRight.getX())
		return false;
	if (p.getY() > this->top || p.getX() < this->bottomRight.getX())
		return false;
	return true;
}

void Rectangle::moveRect(double deltaLeft, double deltaTop)
{
	this->left = this->left + deltaLeft;
	this->top = this->top + deltaTop;
	topLeft.setX(this->left);
	topLeft.setY(this->top);
}
void Rectangle::scaleRect(double rectWidth, double rectHeight)
{
	this->width = this->width + rectWidth;
	this->height = this->height + rectHeight;
	bottomRight.setX(this->left - this->width);
	bottomRight.setY(this->top - this->height);
}




