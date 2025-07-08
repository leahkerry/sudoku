/***********************************************
 *                   ARITH 
 * Created: 7/6/25
 * Purpose: Functions defined to assist in 
 *          vector operations
 ***********************************************/

#ifndef ARITH_H
#define ARITH_H

#include <vector> 
#include <random>
#include <chrono>
#include <algorithm>

using namespace std; 

vector<int> permute_digits(int fullSize);
int get_random(int start, int end);

#endif