#include <iostream>

//types
struct Guess
{
	char *number;
	int correct;
};

//functions
int compare( char *first, char *second );
void increment( char *guess );
int sumDigits( char *guess );
int combine( int position );
int countUnique( int position );

//globals
int length = 16;
int numGuesses = 22;
Guess guesses[] =
{
	{"5616185650518293", 2 },	//0
	{"3847439647293047", 1 },	//1
	{"5855462940810587", 3 },	//2
	{"9742855507068353", 3 },	//3
	{"4296849643607543", 3 },	//4
	{"3174248439465858", 1 },	//5
	{"4513559094146117", 2 },	//6
	{"7890971548908067", 3 },	//7
	{"8157356344118483", 1 },	//8
	{"2615250744386899", 2 },	//9
	{"8690095851526254", 3 },	//10
	{"6375711915077050", 1 },	//11
	{"6913859173121360", 1 },	//12
	{"6442889055042768", 2 },	//13
	{"2321386104303845", 0 },	//14
	{"2326509471271448", 2 },	//15
	{"5251583379644322", 2 },	//16
	{"1748270476758276", 3 },	//17
	{"4895722652190306", 1 },	//18
	{"3041631117224635", 3 },	//19
	{"1841236454324589", 3 },	//20
	{"2659862637316867", 2 }	//21
};

int main( int argc, char *argv[] )
{
	/*
	char guess[] = "00000";
	while (sumDigits( guess ) < 9 * length )
	{
		bool found = true;
		for (int j = 0; j < numGuesses; ++j)
		{
			if (compare( guess, guesses[j].number) != guesses[j].correct)
			{
				found = found && false;
			}
		}
		if (found)
		{
			std::cout << guess << std::endl;
			break;
		}
		increment( guess );
	}
	*/
	for (int i = 0; i < numGuesses; ++i)
	{
		std::cout << i << ": " << countUnique( i ) << std::endl;
	}
}

//assumes that both are the same length - reasonable for this application
int compare( char *first, char *second )
{
	int num = 0;
	for (int i = 0; i < length; ++i)
	{
		if (first[i] == second[i]) ++num;
	}
	return num;
}

bool compareGuesses( char *guess )
{
	int numCorrect = 0;
	for (int i = 0; i < numGuesses; ++i)
	{
		if (compare( guess, guesses[i].number ) == guesses[i].correct)
		{
			++numCorrect;
		}
	}
	if (numCorrect == numGuesses)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void increment( char *guess )
{
	guess[length - 1]++;
	for (int i = length - 1; i >=0; --i)
	{
		if (guess[i] > '9')
		{
			guess[i] = '0';
			guess[i - 1]++;
		}
	}
}

int sumDigits( char *guess)
{
	int result = 0;
	for (int i = 0; i < length; ++i)
	{
		result += (guess[i] - 48);
	}
	return result;
}

int combine( int position )
{
	int count = guesses[position].correct;
	char *guess = guesses[position].number;
	for (int i = 0; i < numGuesses; ++i)
	{
		if (i != position)
		{
			if (compare( guess, guesses[i].number ) == 0)
			{
				count += guesses[i].correct;
			}
		}
	}
	return count;
}

int countUnique( int position )
{
	int count = 0;
	char *guess = guesses[position].number;
	for (int i = 0; i < numGuesses; ++i)
	{
		if (i != position)
		{
			if (compare( guess, guesses[i].number ) == 0)
			{
				count++;
				if (position == 2)
				{
					std::cout << "Unique: " << i << std::endl;
				}
			}
		}
	}
	return count;
}

//assumes that the answer can be found - again, reasonable given framing of question
/*
bool testPosition( char *guess, int position )
{
	bool result = false;

	while (!result)
	{
		if (position < length - 1)
		{
			result = 
		}
	}
	return result;
}
*/
