#include <iostream>

int main( int argc, char *argv[] )
{
	for (int i = 0; i < 100; ++i)
	{
		int num = 3 * i * i - 2 * i - 1;
		if (num % 4 == 0)
		{
			std::cout << i << ", " << num << std::endl;
		}
	}
}
