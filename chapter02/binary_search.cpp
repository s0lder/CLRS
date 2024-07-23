#include <iostream>
#include <vector>

int RecursiveBinarySearch(std::vector<int>& A, int lo, int hi, int x) {
    if (lo > hi)
        return -1;
    
    // (lo + hi) / 2 is unsafe -- potential overflow for large values
    int mid = lo + (hi - lo) / 2;

    if (A[mid] == x)
        return mid;
    else if (x < A[mid])
        RecursiveBinarySearch(A, lo, mid - 1, x);
    else
        RecursiveBinarySearch(A, mid + 1, hi, x);
}

int main() {
    std::vector<int> A = {0, 1, 2, 3, 4, 5, 6};
    int lo = 1, hi = A.size() - 1;

    int x;
    std::cin >> x;

    std::cout << RecursiveBinarySearch(A, lo, hi, x) << std::endl;

    return 0;
}