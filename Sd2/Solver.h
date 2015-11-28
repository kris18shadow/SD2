#pragma once
#include <iostream>
#include "Queue.h"
#include "Cell.h"
#include "Stack.h"
#include "DynamicArray.h"

class Solver
{
private:
	size_t N;
	size_t M;
	
	Cell** cellMap;
	Cell START;

	Queue<Cell*> cellQueue;
	DynamicArray<Cell> availablePaths;
	Cell* pCurrent;

	void tryUp(bool showStep);
	void tryDown(bool showStep);
	void tryRight(bool showStep);
	void tryLeft(bool showStep);
public:
	Solver(size_t N, size_t M, char** cellMap, Cell START);
	~Solver();
	
	void findPath(Cell* END);
	void findAvailableCells();
	void findAllPaths();
};