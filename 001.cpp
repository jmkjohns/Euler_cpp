#include <iostream>

//==============================================================================
int main( int argc, char *argv[] )
//==============================================================================
{
    //declare
    unsigned int limit = 1000;
    unsigned int sum = 0;

    //loop
    for (int i = 1; i < limit; ++i)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }

    //output
    std::cout << sum << std::endl;

}
