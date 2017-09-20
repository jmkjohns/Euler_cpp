#include <iostream>
#include "Common\Sieve.cpp"

//==============================================================================
int main( int argc, char *argv[] )
//==============================================================================
{
    //declare
    Sieve sieve = buildSieve( 2000000 );
    unsigned _int64 sum = 0;

    for (int i = 0; i < sieve.size; ++i)
    {
        sum += sieve.factors[i];
    }

    std::cout << "sum: " << sum << std::endl;
}
