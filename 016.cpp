#include <iostream>

//==============================================================================
int main( int argc, char *argv[] )
//==============================================================================
{
    //declare
    unsigned int power = 1000;
    unsigned int digits = power / 3 + 1;
    unsigned int sum = 0;
    unsigned char carry = 0;
    unsigned char *number = new unsigned char[digits];

    //clear memory and initialise
    memset( number, 0, digits );
    number[0] = 1;

    //multiply
    for (unsigned int i = 0; i < power; ++i)
    {
        for (unsigned int j = 0; j < digits; ++j)
        {
            number[j] *= 2;
            number[j] += carry;

            if (number[j] > 9)
            {
                number[j] %= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
        }
    }

    //output
    for (unsigned int i = 0; i < digits; ++i)
    {
        sum += number[i];
    }
    std::cout << sum << std::endl;
}
