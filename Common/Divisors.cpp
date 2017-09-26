#ifndef __DIVISORS__
#define __DIVISORS__

#include "Common/intRoot.h"

INTROOT( unsigned int )

//==============================================================================
unsigned int sumProperDivisors( unsigned int number )
//==============================================================================
{
    //declare 
    unsigned int total = 0;

    if (number > 1)
    {
        unsigned int limit = intRoot( number );
        total = 1;

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
    }
    return total;
}

#endif
