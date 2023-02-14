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


#endif /* H_LA */
