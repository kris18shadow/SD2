#pragma once

class Cell
{
private:
	char symbol;
	size_t x, y;
	bool visited;
public:
	Cell(size_t x = 0, size_t y = 0, char symbol = '.');
	void setX(size_t x);
	void setY(size_t y);
	void setSymbol(char s);
	void markVisited();
	void markUnvisited();

	Cell& operator=(const Cell& other);

	int getX() const;
	int getY() const;
	bool isVisited() const;
	char  getSymbol() const;
	void printCell() const;
};