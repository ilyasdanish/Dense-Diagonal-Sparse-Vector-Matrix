/**
  Lab 1, test1.cpp
  Purpose: Vectors implementation in c++
  Author: Ilyas Yaqoob
*/

#include "la.h"

// ****************************************************************************
//
//  Test the DenseVector class
//
// ****************************************************************************

void testDV()
{
    // General variables
    int             N = 7;
    int             M = 3;
    double          two = 2.0;

    // DenseVector testing
    DenseVector     v1( N );
    v1.print();
    v1.setconst( two );
    v1.newname( "v1" );
    v1.print();
    DenseVector     v2( "v2", N );
    //v2 = v1;
    v2.newname( "v2" );
    v2.print();
    v2.setrandom();
    v2.print();
    DenseVector     v3 = v2;
    v3.newname( "v3" );
    v3.print();
};


// ****************************************************************************
//
//  Test my linear algebra classes and their functions
//
// ****************************************************************************

int main( int argc, char* argv[] )
{
    int testing[] = { 1, 1, 1, 1, 1 };

    srand( time( 0 ) );

    // Statistics testing, part 1
    cout << "***** Statistics testing, part 1" << endl;
    laStatsReset();
    laStatsPrint();
    cout << endl;

    // Class testing
    if ( testing[laStatsDeV] )
    {   cout << "***** DenseVector class testing" << endl;
        testDV();
        cout << endl;
    }

    // Statistics testing, part 2
    cout << "***** Statistics testing, part 2" << endl;
    laStatsPrint();

    // All done
    return 0;
};
