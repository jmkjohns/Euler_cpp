#include <iostream>
#include <cstring>
#include <fstream>

//functions
void addNumber();
void printResults();

//variables
char total[52];
char number[50];
std::ifstream input;

//=============================================================================
int main( int argc, char *argv[] )
//=============================================================================
{
	input.open( "13.txt" );
	memset( &total[0], '0', 50 );
	if (input.good())
	{
		for (int i = 0; i < 100; ++i)
		{
			input.read( &number[0], 50 );
			addNumber();
		}
	}
	input.close();
	printResults();
}


//=============================================================================
void addNumber()
//=============================================================================
{
	int carry = 0;
	for (int i = 51; i >= 0; --i)
	{
		int result = (total[i] - 48) + carry;
		if (i > 1) result += (number[i - 2] - 48);
		carry = result / 10;
		result %= 10;
		total[i] = result + 48;
	}
}


//=============================================================================
void printResults()
//=============================================================================
{
	total[13] = '\0';
	std::cout << total << std::endl;
}
