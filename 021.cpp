#include <iostream>
#include "Common/intRoot.h"

//prototypes
unsigned int sumProperDivisors( unsigned int number );
INTROOT( unsigned int )

//==============================================================================
int main( int argc, char *argv[] )
//==============================================================================
{
    //declare
    unsigned int limit = 10000;
    int total = 0;

    //loop
    for (int i = 3; i < limit; ++i)
    {
        if (sumProperDivisors( sumProperDivisors( i ) ) == i)
        {
            if (i != sumProperDivisors( i ))
            {
                total += i;
            }
        }
    }

    std::cout << total << std::endl;
}


//==============================================================================
unsigned int sumProperDivisors( unsigned int number )
//==============================================================================
{
    //declare 
    unsigned int total = 1;
    unsigned int limit = intRoot( number );

    for (unsigned int i = 2; i < limit; ++i)
    {
        if ( number % i == 0)
        {
            total += i;
            total += (number / i);
        }
    }

    //deal with perfect squares
    if (limit * limit == number)
    {
        total += limit;
    }

    return total;
}
