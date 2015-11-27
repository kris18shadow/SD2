#pragma once
#include <iostream>
#include "Queue.h"
#include "Cell.h"
#include "Stack.h"
#include "DynamicArray.h"

struct Relatives
{
	Cell* parent;
	Cell* child;
};

class Solver
{
private:
	size_t N;
	size_t M;
	
	Cell** cellMap;
	Cell START;

	Queue<Cell*> cellQueue;
	DynamicArray<Relatives> relatives;
	DynamicArray<Cell> availablePaths;
	Cell* pCurrent;

	void tryUp(bool showStep);
	void tryDown(bool showStep);
	void tryRight(bool showStep);
	void tryLeft(bool showStep);
public:
	Solver(int N, int M, char** cellMap, Cell START);
	~Solver();
	void findPath(Cell* END);
	void findAvailableCells();
	void findAllPaths();
};