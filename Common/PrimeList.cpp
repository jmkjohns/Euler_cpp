#include "PrimeList.h"
#include <iostream>

PrimeList::PrimeList( int newUpperLimit ) : upperLimit( newUpperLimit ), primes( NULL ), primeCount( 0 )
{
	if (upperLimit >= 2)
	{
		int numPrimes = upperLimit / 2;
		primes = new int[numPrimes];

		for (int i = 0; i < numPrimes; ++i)
		{
			primes[i] = 0;
		}

		int *numbers = new int[upperLimit - 1];
		for (int i = 0; i < upperLimit - 1; ++i)
		{
			numbers[i] = i + 2;
		}

		for (int i = 0; i < upperLimit - 1; ++i)
		{
			if (numbers[i] != 0)
			{
				primes[primeCount] = numbers[i];
				++primeCount;

				int tmpCount = i + numbers[i];
				while (tmpCount < upperLimit - 1)
				{
					numbers[tmpCount] = 0;
					tmpCount += numbers[i];
				}
			}
		}

		delete [] numbers;
	}
}


PrimeList::~PrimeList()
{
	delete [] primes;
}


int PrimeList::getUpperLimit()
{
	return upperLimit;
}


int& PrimeList::operator[] ( const int index )
{
	if (index < 0 || index >= primeCount)
	{
		int tmp = 0;
		return tmp;
	}

	return primes[index];
}


void PrimeList::printPrimes()
{
	for (int i = 0; i < primeCount; ++i)
	{
		std::cout << primes[i] << std::endl;
	}
}
