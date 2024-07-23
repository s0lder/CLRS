#include <iostream>
#include <vector>

void Insert(std::vector<int>& A, int n) {
    int key = A[n];
    int i = n - 1;

    while (i > 0 && A[i] > key) {
        A[i + 1] = A[i];
        --i;
    }

    A[i + 1] = key;
}

void RecursiveInsertionSort(std::vector<int>& A, int n) {
    if (n < 1)
        return;

    RecursiveInsertionSort(A, n - 1);
    Insert(A, n);
}

void PrintArray(std::vector<int>& A, int n) {
    for (int i = 1; i <= n; i++)
        std::cout << A[i] << ' ';
    std::cout << std::endl;
}

int main() {
    std::vector<int> A = {0, 5, 2, 4, 6, 1, 3};

    RecursiveInsertionSort(A, A.size() - 1);
    PrintArray(A, A.size() - 1);
}