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
//  Test the DenseMatrix class
//
// ****************************************************************************

void testDeM()
{
    // General variables
    int             N = 3;
    int             M = 2;
    double          two = 2.0;
    double          ip;

    // DenseMatrix testing
    DenseMatrix     m1( N );
    m1.print();
    m1.setconst( two );
    m1.newname( "m1" );
    m1.print();
    DenseVector     v1( "v1", N );
    v1.setrandom();
    v1.print();
    ip = m1.rowxvec( 0, v1 );
    cout << "(row 0,v1) = " << ip << endl;
    ip = m1.rowxvec( 2, v1 );
    cout << "(row 2,v1) = " << ip << endl;
    DenseMatrix     m2( "m2", N + 1 );
    m2.setspd();
    m2.print();
    DenseMatrix     m3( "m3", N, M );
    m3.setrandom();
    m3.print();
    m3.getcol( 1, v1 );
    v1.print();
    DenseMatrix     m4 = m1;
    m4.newname( "m4" );
    m4.print();
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

    if ( testing[laStatsDeM] )
    {   cout << "***** DenseMatrix class testing" << endl;
        testDeM();
        cout << endl;
    }

    // Statistics testing, part 2
    cout << "***** Statistics testing, part 2" << endl;
    laStatsPrint();

    // All done
    return 0;
};
