#include <iostream>
#include <algorithm>
#include <vector>

int HasSum(std::vector<int>& A, int target) {
    std::sort(A.begin(), A.end());

    int lo = 1, hi = A.size() - 1;

    while (lo < hi) {
        int sum = A[lo] + A[hi];
        if (sum == target)
            return 1;
        else if (sum > target)
            --hi;
        else
            ++lo;
    }
    return -1;
}

int main() {
    std::vector<int> A = {0, 1, 2, 3, 4, 5, 6};

    int target = 5;

    std::cout << HasSum(A, target) << std::endl;

    return 0;
}