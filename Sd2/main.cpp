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
	std::cout << "N and M are set to: " << N << "," << M << std::endl;
		
	// Enter Map:
	char** map = new char*[N];
	for (size_t i = 0; i < N; i++)
		map[i] = new char[M];

	//Start point input:
	size_t xStart, yStart;
	std::cout << "Enter X and Y of start point: ";
	std::cin >> xStart >> yStart;
	std::cout << "\nStart is set to: " <<  xStart << "," << yStart << std::endl;
	Cell start('.', xStart, yStart);

	MapSolver solve(N,M, map,start);

	
	//DELETION:
	for (size_t i = 0; i < N; i++)
		delete map[i];
	delete map;

	return 0;
}