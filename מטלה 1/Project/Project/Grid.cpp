#include "Grid.h"
#include "Rectangle.h"
#include "Point.h"


Grid::Grid(double tileW, double tileH, int width, int height, int color)
{
	this->tileH = tileH;
	this->tileW = tileW;
	this->width = width;
	this->height = height;
	this->color = color;
	
	this->sumRec = 0;
	this->arrayRec = nullptr;

	int i, j;
	count = height * width;
	recs = new Rectangle * [count];

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
		{
			recs[j + (i * width)] = new Rectangle(j * tileW, tileH * i, tileW, tileH, color);
		}
}



Rectangle* Grid::getRectAtPoint(const Point& p)
{
	/*for (int i=0; i<this->sumRec; i++)
	{
		if (this->arrayRec[i]->contains(p))
			return arrayRec[i];
	}
	return nullptr;*/
	for (int i = 0; i < this->count; i++)
	{
		if (this->recs[i]->contains(p))
			return recs[i];
	}
	return nullptr;
}
Rectangle* Grid::getRectAtIndex(int i)
{
	if (this->count < i)
		return nullptr;
	return this->recs[i];
	
}

void Grid::moveGrid(double deltaLeft, double deltaTop)
{
	for (int i = 0; i < this->sumRec; i++)
	{
		this->arrayRec[i]->moveRect(deltaLeft, deltaTop);
	}
}
void Grid::scaleGrid(double rectWidth, double rectHeight)
{
	for (int i = 0; i < this->sumRec; i++)
	{
		this->arrayRec[i]->scaleRect(rectWidth, rectHeight);
	}
}

Grid::~Grid()
{
	delete[] arrayRec;
}
