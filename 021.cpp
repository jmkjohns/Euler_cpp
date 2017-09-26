#include <iostream>
#include "Common/Divisors.cpp"

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
