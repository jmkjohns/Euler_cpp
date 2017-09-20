#include <iostream>
#include "Common\intRoot.h"

//types
//==============================================================================
struct Sieve
//==============================================================================
{
    unsigned _int32 *factors;
    unsigned _int32 size;
};

//prototypes
INTROOT(unsigned _int64)
Sieve buildSieve( unsigned _int64 num );

//==============================================================================
int main( int argc, char *argv[] )
//==============================================================================
{
    //declare
    unsigned _int64 limit = 600851475143;
    unsigned _int32 maxFactor = 0;
    
    Sieve sieve = buildSieve( limit );
    for (int i = 0; i < sieve.size; ++i)
    {
        if (sieve.factors[i] != 0)
        {
            if (limit % sieve.factors[i] == 0)
            {
                maxFactor = sieve.factors[i];
            }
        }
    }

    //output
    std::cout << maxFactor << std::endl;
}


//==============================================================================
Sieve buildSieve( unsigned _int64 num )
//==============================================================================
{
    //locals
    Sieve sieve;
    sieve.size = intRoot( num );
    sieve.factors = new unsigned _int32[sieve.size];

    //clear memory
    memset( sieve.factors, 0xff, sieve.size * sizeof(unsigned _int32) );

    //build sieve
    for (unsigned _int32 i = 0; i < sieve.size; ++i)
    {
        if (sieve.factors[i] != 0)
        {
            sieve.factors[i] = i + 2;
            for( unsigned _int32 j = i + sieve.factors[i]; j < sieve.size; j += sieve.factors[i] )
            {
                sieve.factors[j] = 0;
            }
        }
    }

    return sieve;
}
