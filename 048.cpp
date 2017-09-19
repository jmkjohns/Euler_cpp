#include <iostream>
#include <cstring>

//functions
void multiply( char *target, int number );
void setNumber( char *target, int number );
void printTotal();
void buildPower( int number );
void add();


//variables
char total[10];
char power[10];


//=============================================================================
int main( int argc, char *argv[] )
//=============================================================================
{
	//clear total to zero
	setNumber( &total[0], 0 );
	for (int i = 1; i <= 1000; ++i)
	{
		buildPower( i );
		add();
	}
	printTotal();
}


//=============================================================================
void multiply( char *target, int number )
//=============================================================================
{
	int carry = 0;
	for (int i = 9; i >= 0; --i)
	{
		int result = (target[i] - 48) * number + carry;
		carry = result / 10;
		result %= 10;
		target[i] = result + 48;
	}
}


//=============================================================================
void printTotal()
//=============================================================================
{
	char output[11];
	for (int i = 0; i < 10; ++i)
	{
		output[i] = total[i];
	}
	output[10] = '\0';
	std::cout << output << std::endl;
}


//=============================================================================
void buildPower( int number )
//=============================================================================
{
	setNumber( &power[0], number );
	for (int i = 0; i < number - 1; ++i)
	{
		multiply( &power[0], number );
	}
}


//=============================================================================
void setNumber( char *target, int number )
//=============================================================================
{
	memset( target, '0', 10 );
	int carry = 0;
	for (int i = 9; i >= 0; --i)
	{
		int result = (target[i] - 48) + number + carry;
		if (number > 0) number = 0;
		carry = result / 10;
		result %= 10;
		target[i] = result + 48;
	}
}


//=============================================================================
void add()
//=============================================================================
{
	int carry = 0;
	for (int i = 9; i >= 0; --i)
	{
		int result = (total[i] - 48) + (power[i] - 48) + carry;
		carry = result / 10;
		result %= 10;
		total[i] = result + 48;
	}
}
