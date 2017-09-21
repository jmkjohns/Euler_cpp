#include <iostream>

//==============================================================================
int main( int argc, char *argv[] )
//==============================================================================
{
    //letter counts
    int units[] = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 };
    int tens[] = { 0, 0, 6, 6, 5, 5, 5, 7, 6, 6 };
    int hundreds[] = { 0, 7, 7, 7, 7, 7, 7, 7, 7, 7 };
    int thousands[] = { 0, 8, 8, 8, 8, 8, 8, 8, 8, 8 };
    int And = 3;

    //declare
    int sum = 0;

    for (int i = 1; i <= 1000; ++i)
    {
        //tens and units
        if ((i / 10) % 10 ==1)
        {
            sum += units[i % 100];
        }
        else
        {
            sum += units[i % 10];
            sum += tens[(i / 10) % 10];
        }

        //hundreds
        sum += units[(i / 100) % 10];
        sum += hundreds[(i / 100) % 10];

        //thousands
        sum += units[(i / 1000) % 10];
        sum += thousands[(i / 1000) % 10];

        //ands
        if (i > 100 && (i % 100) != 0) sum += And;
    }

    std::cout << sum << std::endl;
}
