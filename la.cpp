/**
  Lab 1, la.cpp
  Purpose: Vectors implementation in c++
  Author: Ilyas Yaqoob
*/

#include "la.h"

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

int      laStats[laStatsSpM2+1][laStatsDes+1];   // Statistics matrix


// ****************************************************************************
//
// Statistics function(s)
//
// ****************************************************************************

// Zero all statistics
void laStatsReset()
{
    for( int i = laStatsDeV; i < laStatsSpM2; i++ )
        for( int j = laStatsCon; j < laStatsDes; j++ )
            laStats[i][j] = 0;
};

// Increment one of the counters
void laStatsIncrement( int wclass, int wopr )
{
    if ( wclass >= laStatsDeV && wclass <= laStatsSpM2 &&
         wopr >= laStatsCon && wopr <= laStatsDes )
        laStats[wclass][wopr]++;
};

// Print the statistics
void laStatsPrint()
{
    for( int i = laStatsDeV; i <= laStatsSpM2; i++ )
    {
        if ( i == laStatsDeV )
            cout << "DenseVector:    ";
        cout << laStats[i][laStatsCon] << "," 
             << laStats[i][laStatsCop] << "," 
             << laStats[i][laStatsDes] << endl;
    }
};
