#include <iostream>

void add( int &total, int a, int b )
{
	int n = 4 * b + a;
	if (n < 4000000 )
	{
		total += n;
		add( total, b, n );
	}
}

int main()
{
	int total = 10;
	add( total, 2, 8 );
	std::cout << total << std::endl;
}
