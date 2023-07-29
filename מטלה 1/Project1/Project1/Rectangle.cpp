#include "Rectangle.h"

#include <cmath>

#include "Point.h"

int Rectangle::m_count = 0;



Rectangle::Rectangle(double left, double top, double width, double height, int color)
{
	this->left = left;
	this->top = top;
	this->width = width;
	this->height = height;
	topLeft = Point(left, top);
	bottomRight = Point(width + left, height + top);
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
	return topLeft;
}
Point& Rectangle::getBottomRightPoint()
{
	return bottomRight;
}

bool  Rectangle::contains(const Point& p)
{
	int x, y, h, w;
	x = p.getX();
	y = p.getY();

	if (p.getX() >= topLeft.getX() && p.getX() <= bottomRight.getX() && p.getY() >= topLeft.getY() && p.getY() <= bottomRight.getY())
		return true;
	else
		return false;

}

void Rectangle::moveRect(double deltaLeft, double deltaTop)
{
	this->left = this->left + deltaLeft;
	this->top = this->top + deltaTop;
	topLeft.setX(this->left);
	topLeft.setY(this->top);
	bottomRight.setX(this->width - this->left);
	bottomRight.setY(this->height - this->top);
}

	
void Rectangle::scaleRect(double rectWidth, double rectHeight)
{
	double width = this->bottomRight.getX() - this->topLeft.getX();
	double height = this->bottomRight.getY() - this->topLeft.getY();

	this->topLeft.setScaleX(rectWidth / width);
	this->topLeft.setScaleY(rectHeight / height);
	this->bottomRight.setScaleX(rectWidth / width);
	this->bottomRight.setScaleY(rectHeight / height);
	//this->height = topLeft.getY() / topLeft.getScaleY() - bottomRight.getY() / bottomRight.getScaleY();
	//this->width = bottomRight.getX() / bottomRight.getScaleX() - topLeft.getX() / topLeft.getScaleX();
	//double scale = abs(rectWidth / width);
	//topLeft.setScaleX(scale);
	//topLeft.setScaleY(scale);
	//bottomRight.setScaleX(scale);
	//bottomRight.setScaleY(scale);

	//topLeft.setX(topLeft.getX() / topLeft.getScaleX());
	//topLeft.setY(topLeft.getY() / topLeft.getScaleY());

	//bottomRight.setX(topLeft.getX() / topLeft.getScaleX());
	//bottomRight.setY(topLeft.getY() / topLeft.getScaleY());

	//this->topLeft.setScaleX(rectWidth / this->width);
	//this->topLeft.setScaleY(rectHeight / this->height);
	//this->bottomRight.setScaleX(rectWidth / this->width);
	//this->bottomRight.setScaleY(rectHeight / this->height);
	//this->width = rectWidth;
	//this->height = rectHeight;

	//this->width = this->width + rectWidth;
	//this->height = this->height + rectHeight;
	//bottomRight.setX(this->left - this->width);
	//bottomRight.setY(this->top - this->height);
}


Rectangle::~Rectangle()
{
	--m_count;
};