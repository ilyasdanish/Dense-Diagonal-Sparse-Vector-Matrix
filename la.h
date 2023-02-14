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

// ****************************************************************************
//
// DenseMatrix class definition
//
// ****************************************************************************

class DenseMatrix {
    public:
        DenseMatrix();                                  // Basic constructor
        DenseMatrix( int N );                           // Basic constructor
        DenseMatrix( string name, int N );              // Named constructor
        DenseMatrix( string name, int N, int M );       // Named constructor
        DenseMatrix( DenseMatrix& m0 );                 // Copy
        ~DenseMatrix();                                 // Destructor
        void create( int N, int M );                    // Create elements
        void set( int i, int j, double val );           // Element set
        double get( int i, int j );                     // Element get
        int getrows( int i );                           // Get mrows
        void setconst( double val );                    // Set all elements to constant
        void setrandom();                               // Set all elements randomly
        void setrow( int i, DenseVector& v );           // Replace row i
        void getcol( int j, DenseVector& v );           // Get a column
        void setspd();                                  // Set all elements randomly
        double rowxvec( int i, DenseVector& v );        // (row i,v) inner product
        void print();                                   // Print all elements
        void printm();                                  // Print the matrix array
        void newname( string name );                    // Change the name

    private:

    protected:
        double**    mat;
        string      mname;
        int         mcols;
        int         mrows;
};

#endif /* H_LA */
