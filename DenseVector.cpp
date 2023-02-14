/**
  Lab 1, DenseVector.cpp
  Purpose: Vectors implementation in c++
  Author: Ilyas Yaqoob
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "la.h"
using namespace std;

// Basic constructor
DenseVector::DenseVector( int N ) {
    cout << "Constructor: DenseVector( " << N << " )" << endl;
    vlen = N;
    v = new double[vlen];

    // Count Statistics
    laStatsIncrement(laStatsDeV, laStatsCon);
}

// Named constructor
DenseVector::DenseVector( string name, int N ) {
    cout << "Constructor: DenseVector( " << name << "," << N << " )"  << endl;
    vname = name;
    vlen = N;
    v = new double[vlen];

     // Count Statistics
    laStatsIncrement(laStatsDeV, laStatsCon);
}

// Copy constructor
DenseVector::DenseVector( DenseVector& v0 ) {
    cout << "Copy: DenseVector( " << "DenseVector& " << v0.vname << " )" << endl;
    vlen = v0.vlen;
    v = new double[vlen];
    for (int i = 0; i < vlen; i++) {
        v[i] = v0.v[i];
    }

     // Count Statistics
    laStatsIncrement(laStatsDeV, laStatsCop);
}

// Destructor
DenseVector::~DenseVector() {
    cout << "Destructor: ~DenseVector() for " << vname << endl;
    delete[] v;

     // Count Statistics
    laStatsIncrement(laStatsDeV, laStatsDes);
}

// Element set
void DenseVector::set( int i, double val ) {
    v[i] = val;
}

// Element set by vector
void DenseVector::setvec( double* vn ) {
    for (int i = 0; i < vlen; i++) {
        v[i] = vn[i];
    }
}

// Element get
double DenseVector::get( int i ) {
    return v[i];
}

// Set all elements to constant
void DenseVector::setconst( double val ) {
    for (int i = 0; i < vlen; i++) {
        v[i] = val;
    }
}

// Set all elements randomly
void DenseVector::setrandom() {
    srand(time(NULL));
    for (int i = 0; i < vlen; i++) {
        v[i] = (double)rand() / RAND_MAX;
    }
}

// Print all elements
void DenseVector::print() {
    // Print if vector name present then print vector name else nameless
    if(vname != "")
        cout << "DenseVector " << vname << "(" << vlen << ")" << endl;
    else
        cout << "DenseVector nameless(" << vlen << ")" << endl;
    for (int i = 0; i < vlen; i++) {
         if(vname != "")
            cout << vname << "(" << i << ") = ";
         else
            cout << "nameless(" << i << ") = ";
        cout << v[i] << " " << endl;
    }
}

// Change the name
void DenseVector::newname( string name ) {
    vname = name;
}
