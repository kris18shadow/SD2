#include "Cell.h"
#include <iostream>

Cell::Cell(size_t x, size_t y, char symbol)
{
	this->x = x;
	this->y = y;
	this->symbol = symbol;
	this->visited = false;
}

void Cell::setX(size_t x)
{
	this->x = x;
}

void Cell::setY(size_t y)
{
	this->y = y;
}

bool Cell::isVisited() const
{
	return visited;
}

void Cell::setSymbol(char s)
{
	this->symbol = s;
}

void Cell::markVisited()
{
	this->visited = true;
}

Cell& Cell::operator=(const Cell& other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return *this;
}

int Cell::getX() const
{
	return this->x;
}

int Cell::getY() const
{
	return this->y;
}

char Cell::getSymbol() const
{
	return this->symbol;
}

void Cell::printCell() const
{
	std::cout << " (" << getX() << ", " << getY() << ") ";
}