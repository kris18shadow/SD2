#pragma once
#include <iostream>
#include "Queue.h"
#include "Cell.h"

struct Relatives
{
	Cell* parent;
	Cell* child;
};

class MapSolver
{
private:
	int N;
	int M;
	char** cellMap;
	Cell START;

	Queue<Cell*> CellQueue;
	///////////////////////////////////////////std::vector<Relatives> relatives;
	Cell* pCurrent;

	void tryN();
	void tryS();
	void tryE();
	void tryW();
	void tryNW();
	void tryNE();
	void trySW();
	void trySE();
public:
	MapSolver(int N, int M, char** cellMap, Cell START);
	void findPath();
};

MapSolver::MapSolver(int N, int M, char** cellMap, Cell START)
{
	this->N = N;
	this->M = M;

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			this->cellMap[i][j] = cellMap[i][j];
		}
	}
}