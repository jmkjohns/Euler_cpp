#include <iostream>
#include <fstream>

//==============================================================================
int main( int argc, char *argv[] )
//==============================================================================
{
    //declare
    unsigned int product = 0;
    unsigned int maxProduct = 0;
    int productLength = 4;
    int gridSize = 20;
    unsigned char *data = 0;
    char current = 0;
    std::ifstream input;

    //get data
    input.open( "Resources/011.txt", std::ios::binary );
    if (input.good())
    {
        //allocate and clear memory
        data = new unsigned char[gridSize * gridSize];
        memset( data, 0, gridSize * gridSize );

        //read in data
        for (int i = 0; i < gridSize * gridSize; ++i)
        {
            input.read( &current, 1 );
            data[i] = 10 * (current - '0');
            input.read( &current, 1 );
            data[i] += (current - '0');
        }
    }

    //analyse products
    if (data)
    {
        for (int i = 0; i < gridSize * gridSize; ++i)
        {
            //only test if number is not 0
            if (data[i])
            {
                //left - right products
                if (i % gridSize <= (gridSize - productLength))
                {
                    product = 1;
                    for (int j = 0; j < productLength; ++j)
                    {
                        product *= data[i + j];
                    }

                    if (product > maxProduct)
                    {
                        maxProduct = product;
                    }
                }

                //up - down products
                if (i / gridSize <= (gridSize - productLength))
                {
                    product = 1;
                    for (int j = 0; j < productLength; ++j)
                    {
                        product *= data[i + gridSize * j];
                    }

                    if (product > maxProduct)
                    {
                        maxProduct = product;
                    }
                }

                //left to right diagonal products
                if ((i % gridSize <= (gridSize - productLength)) && (i / gridSize <= (gridSize - productLength)))
                {
                    product = 1;
                    for (int j = 0; j < productLength; ++j)
                    {
                        product *= data[i + (gridSize * j) + j];
                    }

                    if (product > maxProduct)
                    {
                        maxProduct = product;
                    }
                }

                //right to left diagaonal products
                if ((i % gridSize >= (productLength - 1)) && (i / gridSize <= (gridSize - productLength)))
                {
                    product = 1;
                    for (int j = 0; j < productLength; ++j)
                    {
                        product *= data[i + (gridSize * j) - j];
                    }

                    if (product > maxProduct)
                    {
                        maxProduct = product;
                    }
                }
            }
        }
    }

    //tidy up
    input.close();

    //output
    std::cout << maxProduct << std::endl;
}
