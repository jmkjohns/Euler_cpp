#include <iostream>
#include <cstdint>

//functions


//variables
int limit = 1000000;
uint64_t *numbers;
int steps = 0;
int maxSteps = 0;
uint64_t biggest = 0;

int main( int argc, char *argv[] )
{
	numbers = new uint64_t[limit];
	for (int i = 0; i < limit; ++i)
	{
		numbers[i] = i;
	}

	for (int i = limit - 1; i >= 2; --i)
	{
		if (numbers[i] != 0)
		{
			steps = 0;
			uint64_t current = numbers[i];
			while (current != 1)
			{
				++steps;
				numbers[i] = 0;
				if (current % 2 == 0)
				{
					current /= 2;
				}
				else
				{
					current = current * 3 + 1;
				}
			}
			if  (steps > maxSteps)
			{
				maxSteps = steps;
				biggest = i;
			}
			
		}	
	}
	std::cout << biggest << std::endl;
}
