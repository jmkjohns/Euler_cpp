#include <iostream>

int reverse( int num)
{
	int result = 0;
	int remainder;

	while (num > 0)
	{
		remainder = num % 10;
		result = result * 10 + remainder;
		num /= 10;
	}
	return result;
}

bool isPalindrome( int num )
{
	if (num == reverse(num))
	{
		return true;
	}
	return false;
}

int main()
{
	int result = 0;

	for (int i = 0; i < 1000; ++i)
	{
		for (int j = 0; j < 1000; ++j)
		{
			int num = i * j;
			if (isPalindrome( num ))
			{
				if (num > result)
				{
					result = num;
				}
			}
		}
	}

	std::cout << result << std::endl;
}
