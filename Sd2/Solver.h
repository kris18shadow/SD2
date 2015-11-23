#pragma once
#include <iostream>
#include "Queue.h"
#include "Cell.h"

struct Relatives
{
	Cell* parent;
	Cell* child;
};

class Solver
{
private:
	int N;
	int M;


	Cell** cellMap;
	Cell START;

	Queue<Cell*> cellQueue;
	Queue<Relatives> relatives;
	Cell* pCurrent;

	void tryUp(bool showStep);
	void tryDown(bool showStep);
	void tryRight(bool showStep);
	void tryLeft(bool showStep);
public:
	Solver(int N, int M, char** cellMap, Cell START);
	~Solver();
	void findPath();
	void findAllPaths();
};

Solver::Solver(int N, int M, char** Map, Cell START)
{
	this->N = N;
	this->M = M;

	//Generate cell map:
	this->cellMap = new Cell*[N];
	for (size_t i = 0; i < N; i++)
		this->cellMap[i] = new Cell[M];

	//Assign values:
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			this->cellMap[i][j].setX(i);
			this->cellMap[i][j].setY(j);
			this->cellMap[i][j].setSymbol(Map[i][j]);
		}
	}

	this->START = START;
}

Solver::~Solver()
{	
	//Handle dynamically allocated memory:
	for (size_t i = 0; i < N; i++)
		delete this->cellMap[i];
	delete this->cellMap;
}

void Solver::findPath()
{

}

void Solver::findAllPaths()
{
	Cell* pStart = &START;
	cellQueue.push(pStart);
	bool noPath = true;

	while (!cellQueue.empty())
	{

		pCurrent = cellQueue.peek();
		pCurrent->markVisited();
		cellMap[pCurrent->getX()][pCurrent->getY()].markVisited();
		cellQueue.pop();


		tryUp(true);
		tryDown(true);
		tryRight(true);
		tryLeft(true);
	}
}

void Solver::tryUp(bool showStep)
{
	if (pCurrent->getY() - 1 >= 0
		&& cellMap[pCurrent->getX()][pCurrent->getY() - 1].getSymbol() == '.'
		&& !(cellMap[pCurrent->getX()][pCurrent->getY() - 1].isVisited()))
	{
		cellQueue.push(&cellMap[pCurrent->getX()][pCurrent->getY() - 1]);
		cellMap[pCurrent->getX()][pCurrent->getY() - 1].markVisited();

		Relatives temp;
		temp.child = &cellMap[pCurrent->getX()][pCurrent->getY() - 1];
		temp.parent = pCurrent;
		relatives.push(temp);

		if (showStep)
			cellMap[pCurrent->getX()][pCurrent->getY() - 1].printCell();
	}
}

void Solver::tryDown(bool showStep)
{
	if (pCurrent->getY() + 1 < M
		&& cellMap[pCurrent->getX()][pCurrent->getY() + 1].getSymbol() == '.'
		&& !(cellMap[pCurrent->getX()][pCurrent->getY() + 1].isVisited()))
	{
		cellQueue.push(&cellMap[pCurrent->getX()][pCurrent->getY() + 1]);
		cellMap[pCurrent->getX()][pCurrent->getY() + 1].markVisited();

		Relatives temp;
		temp.child = &cellMap[pCurrent->getX()][pCurrent->getY() + 1];
		temp.parent = pCurrent;
		relatives.push(temp);

		if (showStep)
			cellMap[pCurrent->getX()][pCurrent->getY() + 1].printCell();
	}
}

void Solver::tryRight(bool showStep)
{
	if (pCurrent->getX() + 1 < N
		&& cellMap[pCurrent->getX() + 1][pCurrent->getY()].getSymbol() == '.'
		&& !(cellMap[pCurrent->getX() + 1][pCurrent->getY()].isVisited()))
	{
		cellQueue.push(&cellMap[pCurrent->getX() + 1][pCurrent->getY()]);
		cellMap[pCurrent->getX() + 1][pCurrent->getY()].markVisited();

		Relatives temp;
		temp.child = &cellMap[pCurrent->getX() + 1][pCurrent->getY()];
		temp.parent = pCurrent;
		relatives.push(temp);

		if (showStep)
			cellMap[pCurrent->getX() + 1][pCurrent->getY()].printCell();
	}
}

void Solver::tryLeft(bool showStep)
{
	if (pCurrent->getX() - 1 >= 0
		&& cellMap[pCurrent->getX() - 1][pCurrent->getY()].getSymbol() == '.'
		&& !(cellMap[pCurrent->getX() - 1][pCurrent->getY()].isVisited()))
	{
		cellQueue.push(&cellMap[pCurrent->getX() - 1][pCurrent->getY()]);
		cellMap[pCurrent->getX() - 1][pCurrent->getY()].markVisited();

		Relatives temp;
		temp.child = &cellMap[pCurrent->getX() - 1][pCurrent->getY()];
		temp.parent = pCurrent;
		relatives.push(temp);

		if (showStep)
			cellMap[pCurrent->getX() - 1][pCurrent->getY()].printCell();
	}
}