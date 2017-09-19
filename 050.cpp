#include <iostream>

int main()
{
	int limit = 100;
	int * numbers = new int[limit];
	for (int i = 0; i < limit; ++i)
	{
		numbers[i] = i + 1;
	}

	for (int i = 1; i < limit; ++i)
	{
		int base = numbers[i];
		if (base != 0) 
		{
			int index = 2 * base - 1;

			while (index < limit)
			{
				numbers[index] = 0;
				index += base;
			}
		}
	}

	for (int i = 0; i < limit; ++i)
	{
		std::cout << numbers[i] << std::endl;
	}
}
