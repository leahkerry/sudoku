#include "arith.h"

vector<int> permute_digits(int fullSize) {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    shuffle(v.begin(), v.end(), default_random_engine(seed));
    return v;
}