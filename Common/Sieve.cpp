#include <cstring>
#include "intRoot.h"

INTROOT(unsigned int)

//==============================================================================
struct Sieve
//==============================================================================
{
    unsigned int *factors;
    unsigned int size;
};


//==============================================================================
Sieve primeFactors( unsigned int num )
//==============================================================================
{
    //locals
    Sieve sieve;
    sieve.size = intRoot( num );
    sieve.factors = new unsigned int[sieve.size];

    //clear memory
    memset( sieve.factors, 0xff, sieve.size * sizeof(unsigned int) );

    //build sieve
    for (unsigned int i = 0; i < sieve.size; ++i)
    {
        if (sieve.factors[i] != 0)
        {
            sieve.factors[i] = i + 2;

            for( unsigned int j = i + sieve.factors[i]; j < sieve.size; j += sieve.factors[i] )
            {
                sieve.factors[j] = 0;
            }

            if (num % sieve.factors[i] != 0)
            {
                sieve.factors[i] = 0;
            }
        }
    }

    return sieve;
}


//==============================================================================
Sieve buildSieve( unsigned int num )
//==============================================================================
{
    //locals
    Sieve sieve;
    sieve.size = num - 2;
    sieve.factors = new unsigned int[sieve.size];

    //clear memory
    memset( sieve.factors, 0xff, sieve.size * sizeof(unsigned int) );

    //build sieve
    for (unsigned int i = 0; i < sieve.size; ++i)
    {
        if (sieve.factors[i] != 0)
        {
            sieve.factors[i] = i + 2;
            for (unsigned int j = i + sieve.factors[i]; j < sieve.size; j += sieve.factors[i] )
            {
                sieve.factors[j] = 0;
            }
        }
    }

    return sieve;
}
