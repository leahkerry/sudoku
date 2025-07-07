

#include "arith.h"

vector<int> permute_digits(int fullSize) {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    vector<int> v = {};
    for (int i = 1; i <=fullSize; i++) {
        v.push_back(i);
    }
    shuffle(v.begin(), v.end(), default_random_engine(seed));
    return v;
}

int get_random(int start, int end) {
    mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<> distrib(start,end);
    return distrib(gen);
}