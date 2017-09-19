#include <iostream>

void moveIndices( int *grid, int size )
{
	int index = size - 2;
	while ( grid[index] == index + 1 + size )
	{
		--index;
	}
	grid[index]++;
	for (int i = index + 1; i < size; ++i)
	{
		grid[i] = grid[i - 1] + 1;	
	}
}

int main( int argc, char *argv[] )
{
	int size = 20;
	int *grid = new int[size];
	int index = size - 1;
	long count = 0;

	//initialise grid positions
	for (int i = 0; i < size; ++i)
	{
		grid[i] = i + 1;
	}

	//move through the grid
	while (grid[0] == 1)
	{
		count++;
		grid[index]++;	
		if (grid[index] > 2 * size)
		{
			moveIndices( grid, size );
		}
		/*
		for (int i = 0; i < size; ++i)
		{
			std::cout << grid[i] << ":";
		}
		std::cout << std::endl;
		*/
	}

	//output
	std::cout << 2l * count << std::endl;
}
