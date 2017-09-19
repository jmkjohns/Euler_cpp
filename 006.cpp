#include <iostream>

int sumOfSquares( int num );
int squareOfSums( int num );

int main( int argc, char *argv[] )
{
	std::cout << sumOfSquares( 100 ) - squareOfSums( 100 ) << std::endl;
}

int sumOfSquares( int num )
{
	int result = 0;
	for (int i = 1; i <= num; ++i)
	{
		result += i * i;
	}
	return result;
}

int squareOfSums( int num )
{
	int result = 0;
	for (int i = 1; i <= num; ++i)
	{
		result += i;
	}
	return result * result;
}
