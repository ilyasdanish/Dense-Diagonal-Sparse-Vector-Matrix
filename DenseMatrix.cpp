/**
  Lab 1, DenseMatrix.cpp
  Purpose: Vectors implementation in c++
  Author: Ilyas Yaqoob
*/

#include "la.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

// Basic constructor
DenseMatrix::DenseMatrix() {
    cout << "Constructor: DenseMatrix" << endl;    
    mname = "";
    mcols = 0;
    mrows = 0;
    mat = nullptr;

    // Count Statistics
    laStatsIncrement(laStatsDeM, laStatsCon);
}

// Basic constructor with size N
DenseMatrix::DenseMatrix(int N) {
  cout << "Constructor: DenseMatrix( " << N << " )" << endl;    
    mname = "";
    mcols = N;
    mrows = N;
    create(mrows, mcols);
    
    // Count Statistics
    laStatsIncrement(laStatsDeM, laStatsCon);
}

// Named constructor with name and size N
DenseMatrix::DenseMatrix(string name, int N) {
    cout << "Constructor: DenseMatrix( " << name << "," << N << " )"  << endl;
    mname = name;
    mcols = N;
    mrows = N;
    create(mrows, mcols);

    // Count Statistics
    laStatsIncrement(laStatsDeM, laStatsCon);
}

// Named constructor with name, size N, and size M
DenseMatrix::DenseMatrix(string name, int N, int M) {
    cout << "Constructor: DenseMatrix( " << name << "," << N << "," << M << " )"  << endl;
    mname = name;
    mcols = M;
    mrows = N;
    create(mrows, mcols);

    // Count Statistics
    laStatsIncrement(laStatsDeM, laStatsCon);
}

// Copy constructor
DenseMatrix::DenseMatrix(DenseMatrix& m0) {
    cout << "Copy: DenseMatrix( " << "DenseMatrix& " << m0.mname << " )" << endl;
    mname = m0.mname + "_copy";
    mcols = m0.mcols;
    mrows = m0.mrows;
    mat = new double*[mrows];
    for (int i = 0; i < mrows; i++) {
        mat[i] = new double[mcols];
        for (int j = 0; j < mcols; j++) {
            mat[i][j] = m0.mat[i][j];
        }
    }

    // Count Statistics
    laStatsIncrement(laStatsDeM, laStatsCop);
}

// Destructor
DenseMatrix::~DenseMatrix() {
    cout << "Destructor: ~DenseMatrix() for " << mname << endl;
    for (int i = 0; i < mrows; i++) {
        delete[] mat[i];
    }
    delete[] mat;

    // Count Statistics
    laStatsIncrement(laStatsDeM, laStatsDes);
}

// Create elements with rows N and columns M
void DenseMatrix::create(int N, int M) {
    mcols = M;
    mrows = N;
    mat = new double*[mrows];
    for (int i = 0; i < mrows; i++) {
        mat[i] = new double[mcols];
        for (int j = 0; j < mcols; j++) {
            mat[i][j] = 0.0;
        }
    }
}

// Set the element at position i,j to val
void DenseMatrix::set(int i, int j, double val) {
    mat[i][j] = val;
}

// Get the element at position i,j
double DenseMatrix::get(int i, int j) {
    return mat[i][j];
}

// Get the number of rows
int DenseMatrix::getrows(int i) {
    return mrows;
}

// Set all elements to a constant value
void DenseMatrix::setconst(double val) {
    for (int i = 0; i < mrows; i++) {
        for (int j = 0; j < mcols; j++) {
            mat[i][j] = val;
        }
    }
}

// Set all elements randomly
void DenseMatrix::setrandom() {
    srand(time(nullptr));
    for (int i = 0; i < mrows; i++) {
        for (int j = 0; j < mcols; j++) {
            mat[i][j] = (double)rand() / (double)RAND_MAX;
        }
    }
}

// Replace row i with DenseVector v
void DenseMatrix::setrow(int i, DenseVector& v) {
    for (int j = 0; j < mcols; j++) {
        mat[i][j] = v.get(j);
    }
}

// Get a column
void DenseMatrix::getcol(int j, DenseVector& v) {
    for (int i = 0; i < mrows; i++) {
        v.set(i, mat[i][j]);
    }
}

// Set all elements to a random SPD matrix
void DenseMatrix::setspd() {
    srand( time( NULL ) );
    for ( int i = 0; i < mrows; i++ ) {
        for ( int j = i; j < mcols; j++ ) {
            double val = (double)rand() / (double)RAND_MAX;
            mat[i][j] = val;
            mat[j][i] = val;
        }
    }
}

// (row i,v) inner product
double DenseMatrix::rowxvec( int i, DenseVector& v ) {
    double result = 0.0;
    for (int j = 0; j < mcols; j++) {
        result += mat[i][j] * v.get(j);
    }
    return result;
}

void DenseMatrix::print() { 
    // Print if vector name present then print vector name else nameless
    if(mname != "")
        cout << "DenseMatrix " << mname << "(" << mrows << "," << mcols << ")" << endl;
    else
        cout << "DenseMatrix nameless" << "(" << mrows << "," << mcols << ")" << endl;
    
    // Print matrix values    
    for(int i=0; i<mrows; i++) { 
        for(int j=0; j<mcols; j++) {
            if(mname != "")
                cout << mname << "(" << i << "," << j << ") = ";
            else
                cout << "nameless" << "(" << i << "," << j << ") = ";
            cout << get(i,j) << " " << endl; 
        }
    } 
}

void DenseMatrix::printm() { 
    for(int i=0; i<mrows; i++) { 
        for(int j=0; j<mcols; j++) 
            cout << setw(4) << &mat[i][j] << " "; cout << endl; 
    }
}

// Change the name
void DenseMatrix::newname( string name ) {
    mname = name;
}
