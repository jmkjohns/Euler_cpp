#include <iostream>
#include "Common\intRoot.h"

//prototypes
bool isPrime( unsigned int num );
INTROOT(unsigned int)


//==============================================================================
int main( int argc, char *argv[] )
//==============================================================================
{
    //declare
    unsigned int limit = 10001;
    unsigned int count = 2;
    unsigned int current = 3;

    //loop
    while (count < limit)
    {
        if (isPrime( ++current ))
        {
            count++;
        }
    }

    std::cout << current << std::endl;
}


//==============================================================================
bool isPrime( unsigned int num )
//==============================================================================
{
    bool prime = true;
    unsigned int root = intRoot( num );

    for (int i = 2; i <= root; ++i)
    {
        if (num % i == 0)
        {
            prime = false;
        }
    }

    return prime;
}
