#ifndef _PRIMELIST_H_
#define _PRIMELIST_H_

class PrimeList
{
	public:
		//ctor & dtor
		PrimeList( int newUpperLimit );
		~PrimeList();

		int getUpperLimit();
		int& operator[] ( const int index );
		void printPrimes();

	private:
		int upperLimit;
		int primeCount;
		int *primes;
};

#endif
