#include <iostream>

//=============================================================================
struct Perm
//=============================================================================
{
    int *data;
    int *index;
    int count;
};


//=============================================================================
Perm createPerm( int *data, int count )
//=============================================================================
{
    Perm perm;
    perm.data = data;
    perm.count = count;
    perm.index = new int[perm.count];
    for (int i = 0; i < perm.count; ++i)
    {
        perm.index[i] = 0;
    }
    return perm;
}



//=============================================================================
void print( int *data, int count )
//=============================================================================
{
    for (int i = 0; i < count; ++i)
    {
        std::cout << data[i];
    }
    std::cout << std::endl;
}



//=============================================================================
void rotate( int *data, int count )
//=============================================================================
{
    int tmp = data[0];
    for (int i = 0; i < count - 1; ++i)
    {
        data[i] = data[i + 1];
    }
    data[count - 1] = tmp;
}


//=============================================================================
int permute( Perm perm )
//=============================================================================
{
    rotate( &perm.data[perm.count - 2], 2 );
}


//=============================================================================
int main( int argc, char *argv[] )
//=============================================================================
{
    int count = 5;
    int *data = new int[count];
    for (int i = 0; i < count; ++i)
    {
        data[i] = i;
    }

    Perm perm = createPerm( data, count );
}
