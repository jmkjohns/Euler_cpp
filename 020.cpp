#include <iostream>

//==============================================================================
int main( int argc, char *argv[] )
//==============================================================================
{
    //declare
    unsigned int number = 100;
    unsigned int places = number * 2;
    unsigned int total = 0;
    unsigned int *factorial = new unsigned int[places];
    unsigned int carry = 0;

    //initialise
    memset( factorial, 0, places * sizeof( unsigned int ) );
    factorial[0] = 1;

    //calculate factorial
    for (unsigned int num = number; num > 1; --num)
    {
        for (int i = 0; i < places; ++i)
        {
            factorial[i] = factorial[i] * num + (carry % 10);
            carry /= 10;
            carry += factorial[i] / 10;
            factorial[i] %= 10;
        }

        //debug output
        std::cout << num << ": ";
        for (int i = 0; i < places; ++i)
        {
            std::cout << factorial[i] << " ";
        }
        std::cout << std::endl;
    }

    //calculate total
    for (int i = 0; i < places; ++i)
    {
        total += factorial[i];
    }

    //output
    std::cout << total << std::endl;
}
