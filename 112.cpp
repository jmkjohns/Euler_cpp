#include <iostream>

//functions
bool isBouncy( int num );


//=============================================================================
int main( int argc, char *argv[] )
//=============================================================================
{
	int number = 2;
	int bouncy = 0;
	int notBouncy = 1;

	while ((bouncy * 100) / (bouncy + notBouncy) < 99)
	{
		isBouncy( number ) ? ++bouncy : ++notBouncy;
		++number;
	}
	std::cout << bouncy << std::endl;
	std::cout << notBouncy << std::endl;
	std::cout << number << std::endl;
}


//=============================================================================
bool isBouncy( int num )
//=============================================================================
{
	bool ascending = true;
	bool descending = true;
	int previous = num % 10;
	while (num > 0)
	{
		int current = num % 10;
		if (current > previous) ascending = false;
		if (current < previous) descending = false;
		num /= 10;
		previous = current;
	}
	return !(ascending || descending);
}
