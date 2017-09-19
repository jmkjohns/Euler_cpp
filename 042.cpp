#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <ctime>

bool isSquareNumber( int number );
std::string stripQuotes( std::string wordWithQuotes );
int sumLetters( std::string wordToSum );

int main()
{
	clock_t start = clock();
	std::ifstream input;
	input.open( "words.txt");

	int total = 0;
	std::string word;
	char delim = ',';
	
	while (!input.eof())
	{
		std::getline( input, word, delim );
		std::string strippedWord = stripQuotes( word );
		int letterSum = sumLetters( strippedWord );
		bool squareNum = isSquareNumber( 8 * letterSum + 1 );
		if ( squareNum )
		{
			++total;
		}
	}
	clock_t end = clock();
	std::cout << total << std::endl;
	std::cout << (end - start ) << std::endl;
	std::cout << CLOCKS_PER_SEC << std::endl;
}

bool isSquareNumber( int number )
{
	double root, fractPart, intPart;
	root = sqrt( (double)number );
	fractPart = modf( root, &intPart );
	if (fractPart == 0.0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string stripQuotes( std::string wordWithQuotes )
{
	int size = wordWithQuotes.size();
	std::string strippedWord = wordWithQuotes.substr( 1, size - 2 );
	return strippedWord;
}

int sumLetters( std::string wordToSum )
{
	int size = wordToSum.size();
	int letterSum = 0;

	for (int i = 0; i < size; ++i)
	{
		letterSum += (wordToSum[i] - 64);
	}
	return letterSum;
}
