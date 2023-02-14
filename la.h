/**
  Lab 1, la.h
  Purpose: Vectors implementation in c++
  Author: Ilyas Yaqoob
*/


// ****************************************************************************
//
//  la class functions
//
//  #define's of interest
//      LAStatsCollect  This is collect statistics on each time a constructor,
//                      copy, or destructor function is called.
//      LADebug         This will print extra information and do index
//                      verification.
//
// ****************************************************************************

#ifndef H_LA
#define H_LA

#include <iostream>
#include <string>

using namespace std;

// ****************************************************************************
//
// Statistics mechanism
//
// ****************************************************************************

enum laClasses {                                // Statistics class indices
    laStatsDeV = 0,
    laStatsDeM,
    laStatsDiM,
    laStatsSpM1,
    laStatsSpM2 };
enum laFns {                                    // Statistics function indices
    laStatsCon = 0,
    laStatsCop,
    laStatsDes };

void laStatsReset();                            // Zero all statistics
void laStatsIncrement( int wclass, int wopr );  // Increment one of the counters
void laStatsPrint();                            // Print the statistics

// ****************************************************************************
//
// DenseVector class definition
//
// ****************************************************************************

class DenseVector {
    public:
        DenseVector( int N );                   // Basic constructor
        DenseVector( string name, int N );      // Named constructor
        DenseVector( DenseVector& v0 );         // Copy
        ~DenseVector();                         // Destructor
        void set( int i, double val );          // Element set
        void setvec( double* vn );              // Element set
        double get( int i );                    // Element get
        void setconst( double val );            // Set all elements to constant
        void setrandom();                       // Set all elements randomly
        void print();                           // Print all elements
        void newname( string name );            // Change the name

    private:
        string      vname;
        int         vlen;
        double*     v;

    protected:
};

#endif /* H_LA */
