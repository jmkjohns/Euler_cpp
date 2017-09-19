#include <iostream>

int main( int argc, char *argv[] )
{
	int result = 0;
	for (int a = 1; a < 998; ++a)
	{
		for (int b = a + 1; b < 999; ++b)
		{
			for (int c = b + 1; c < 1000; ++c)
			{
				if ((a*a + b*b == c*c) && (a + b + c == 1000))
				{
					std::cout << a << ", " << b << ", " << c << std::endl;
					result = a * b * c;
				}
			}
		}
	}
	std::cout << result << std::endl;
}
