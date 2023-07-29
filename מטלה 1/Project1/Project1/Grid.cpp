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
	int c = 0;
	for (j = 0; j < width; j++)
	{
		for (i = 0; i < height; i++)
		{
			//recs[j + (width * i)] = new Rectangle(j * tileW, tileH * i, tileW, tileH, color);
			recs[c] = new Rectangle(j * tileW, tileH * i, width, height, color);
			c++;
		}


	}

}



Rectangle* Grid::getRectAtPoint(const Point& p)
{

	for (int i = 0; i < count; i++)
		if (recs[i]->contains(p))
		{

			return (recs)[i];
		}
	return (recs)[0];
}

Rectangle* Grid::getRectAtIndex(int i)
{
	return recs[i];

}

void Grid::moveGrid(double deltaLeft, double deltaTop)
{
	for (int i = 0; i < this->sumRec; i++)
	{
		this->recs[i]->moveRect(deltaLeft, deltaTop);
	}
}
void Grid::scaleGrid(double rectWidth, double rectHeight)
{
	for (int i = 0; i < this->sumRec; i++)
	{
		this->recs[i]->scaleRect(rectWidth, rectHeight);
	}
}

Grid::~Grid()
{
	for (int i = 0; i < this->count; ++i) {
		delete this->recs[i];
	}
	if (this->recs != nullptr)
		delete[]this->recs;
	//delete[]recs;
}
