#include <iostream>
#include <fstream>
#include <cmath>

//types
struct 
{
	double value;
	int line;
} biggun;


//=============================================================================
int main( int argc, char *argv[] )
//=============================================================================
{
	//initialise biggun
	biggun.value = 0.0;
	biggun.line = 0;

	//set up stream to read data
	std::ifstream input;
	input.open( "p099_base_exp.txt" );
	if (input.good())
	{
		//initialise data
		int lineNumber = 0;
		int base = 0;
		int exp = 0;

		//iterate through file
		while (!input.eof())
		{
			input >> base;
			input >> exp;
			++lineNumber;

			double result = exp * log10( base );
			if (result > biggun.value)
			{
				biggun.value = result;
				biggun.line = lineNumber;
			}
		}
	}
	input.close();

	std::cout << biggun.line << std::endl;
}
