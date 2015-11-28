#include <iostream>
#include <fstream>
#include <string>
#include "Solver.h"
#include "Queue.h"
#include "Cell.h"


int main()
{
	//N and M input:
	size_t N, M;
	std::cout << "Enter N and M: ";
	std::cin >> N >> M;
	if (N <= 0 || M <= 0 || !std::cin)
	{
		std::cerr << "Bad input!\n";
		return 1;
	}
	std::cout << "N and M are set to: " << N << "," << M << std::endl;
		
	//Allocate Map:
	char** map = new char*[N];
	for (size_t i = 0; i < N; i++)
		map[i] = new char[M];

	//Enter Map:
	std::cout << "Enter map:\n";
	char* buffer = new char[M+1];
	for (size_t i = 0; i < N; i++)
	{
		std::cout << "Enter line No." << i << ": ";
		std::cin >> buffer;

		if (strlen(buffer) != 3)
		{
			std::cerr << "Bad Input!\n";
			return 1;
		}

		for (size_t k = 0; k < M; k++)
			map[i][k] = buffer[k];
	}
			

	//Start point input:
	size_t xStart, yStart;
	std::cout << "Enter X and Y of start point: ";
	std::cin >> xStart >> yStart;
	if (xStart < 0 || yStart < 0 || xStart > N-1 || yStart > M-1 || !std::cin)
	{
		std::cerr << "Bad input!\n";
		return 1;
	}
	
	//Creating Starting cell: 
	Cell start(xStart, yStart, '.');
	std::cout << "\nStart is set to: ";
	start.printCell();

	//Creating solver:
	Solver solve(N,M, map,start);
	std::cout << "\n\nAll available cells: ";
	solve.findAvailableCells();
	solve.findAllPaths();

	
	//DELETION:
	for (size_t i = 0; i < N; i++)
		delete map[i];
	delete map;	
	delete[] buffer;

	return 0;
}