#include <iostream>
#include <cstdint>

uint64_t current = 1;

void next();
int countDivisors( uint64_t number );
int * buildPrimeList( int number );
uint64_t primeProducts( int number );

int main( int argc, char *argv[] )
{
	/*
	uint64_t lowerLimit = primeProducts( divisorLimit );
	while (current < lowerLimit)
	{
		next();
	}
	*/
	int divisors = 0;
	int divisorLimit = 500;

	while (divisors <= divisorLimit)
	{
		divisors = countDivisors( current );
		//next();
		current++;
		std::cout << current << ": " << divisors << std::endl;
	}

	/*
	std::cout << current << std::endl;
	*/
}

void next()
{
	current += counter;
	counter++;
}

int countDivisors( uint64_t number )
{
	int divisors = 0;
	for (uint64_t i = 1; i <= number; ++i)
	{
		if (number % i ==0) ++divisors;
	}
	return divisors;
}

int * buildPrimeList( int number )
{
	int *primeList = new int[number];
	for (int i = 0; i < number; ++i)
	{
		primeList[i] = i + 1;
	}
	for (int i = 1; i < number; ++i)
	{
		if (primeList[i] != 0)
		{
			for (int index = i + primeList[i]; index < number; index += primeList[i])
			{
				primeList[index] = 0;
			}
		}
	}
	return primeList;
}

uint64_t primeProducts( int number )
{
	uint64_t product = 1;
	int *primeList = buildPrimeList( number );
	for (int i = 0; i < number; ++i)
	{
		if (primeList[i] != 0)
		{
			product *= primeList[i];
		}
	}
	return product;
}
