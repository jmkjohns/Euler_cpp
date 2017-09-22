#include <iostream>
#include <fstream>

//prototypes
int max( int a, int b);

//==============================================================================
int main( int argc, char *argv[] )
//==============================================================================
{
    //declare
    std::ifstream input;
    int current = 0;
    int finalRowLength = 15;
    int arraySize = finalRowLength * finalRowLength;
    int *data = new int[arraySize];

    //clear memory
    memset( data, 0, arraySize * sizeof( int ) );

    //get data
    input.open( "Resources/18.txt" );
    if (input.good())
    {
        for (int i = 0; i < finalRowLength; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                input >> data[i * finalRowLength + j];
            }
        }

    }

    //calculate path sums
    for (int i = finalRowLength - 2; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
        {
            data[i * finalRowLength + j] += max(
                    data[(i + 1) * finalRowLength + j],
                    data[(i + 1) * finalRowLength + j + 1]);
        }
    }

    std::cout << data[0] << std::endl;
}


//==============================================================================
inline int max( int a, int b)
//==============================================================================
{
    return (a > b) ? a : b;
}
