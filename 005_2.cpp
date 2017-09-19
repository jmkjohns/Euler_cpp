#include <iostream>

int main( int argc, char *argv[] )
{
	int result = 20;

	for (int i = 19; i > 1; --i)
	{
		if (result / i != 0)
		{
			result *= i;
		}
	}
	std::cout << result << std::endl;
}
