#include <iostream>

struct primeList 
{
	int num;
	int *primes;
};

int main()
{
	primeList list;
	list.num = 10;
	list.primes = new int[list.num];
	for (int i = 0; i < list.num; ++i)
	{
		list.primes[i] = 0;
	}

	int upperLimit = 20;
	int *numbers = new int[upperLimit - 1];
	int listCount = 0;

	for (int i = 0; i < upperLimit - 1; ++i)
	{
		numbers[i] = i + 2;
	}

	for (int i = 0; i < upperLimit - 1; ++i)
	{
		if (numbers[i] != 0)
		{
			list.primes[listCount] = numbers[i];
			++listCount;
			int count = i + numbers[i];
			while (count < upperLimit - 1)
			{
				numbers[count] = 0;
				count += numbers[i];
			}
		}
	}

	for (int i = 0; i < list.num; ++i)
	{
		std::cout << list.primes[i] << std::endl;
	}
}
