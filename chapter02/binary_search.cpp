#include <iostream>
#include <vector>

int RecursiveBinarySearch(std::vector<int>& A, int lo, int hi, int x);
int IterativeBinarySearch(const std::vector<int>& A, int x);
void InsertionSort(std::vector<int>& A);

void InsertionSort(std::vector<int>& A) {
    int n = A.size() - 1;

    for (int i = 2; i <= n; i++) {
        int key = A[i];
        int pos = RecursiveBinarySearch(A, 1, i - 1, key);

        for (int j = i - 1; j >= pos; --j)
            A[j + 1] = A[j];
        
        A[pos] = key;
    }
}

int RecursiveBinarySearch(std::vector<int>& A, int lo, int hi, int x) {
    if (lo > hi)
        return lo;
    
    // (lo + hi) / 2 is unsafe -- potential overflow for large values
    int mid = lo + (hi - lo) / 2;

    if (A[mid] == x)
        return mid + 1;
    else if (x < A[mid])
        RecursiveBinarySearch(A, lo, mid - 1, x);
    else
        RecursiveBinarySearch(A, mid + 1, hi, x);
}

int IterativeBinarySearch(const std::vector<int>& A, int x) {
    int lo = 1;
    int hi = A.size() - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (x == A[mid])
            return mid;
        else if (x < A[mid])
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1;
}

int main() {
    std::vector<int> A = {0, 4, 5, 2, 53, 12, 56};
    int lo = 1, hi = A.size() - 1, x = 4;

    InsertionSort(A);

    for (int elem : A)
        std::cout << elem << ' ';
    std::cout << std::endl;

    return 0;
}