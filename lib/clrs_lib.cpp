#include "clrs_lib.h"

#include <random>
#include <chrono>

void FillRandVec(std::vector<int>& vec, int upper_bound, bool zero_indexed) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> rdist(1, upper_bound);

    for (int i = zero_indexed; i < vec.size(); i++)
        vec[i] = rdist(rng);
}