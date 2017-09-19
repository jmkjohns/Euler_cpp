#include <iostream>

int main()
{
	int limit = 20;
	int result = 1;
	int *numbers = new int[limit - 1];

	for (int i = 0; i < limit - 1; ++i)
	{
		numbers[i] = i + 2;
	}

	for (int i = 0; i < limit - 1; ++i)
	{
		result *= numbers[i];
		int tmp = numbers[i];

		for (int j = i; j < limit -1; ++j)
		{
			if (numbers[j] % tmp == 0)
			{
				numbers[j] /= tmp;
			}
		}
	}

	std::cout << result << std::endl;
}
