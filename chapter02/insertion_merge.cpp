#include <iostream>
#include <vector>

const int treshold = 16;

void InsertionSort(std::vector<int>& A, int lo, int hi) {
    for (int i = lo + 1; i <= hi; i++) {
        int key = A[i];

        int j = i - 1;
        while (j >= lo && A[j] > key) {
            A[j + 1] = A[j];
            --j;
        }

        A[j + 1] = key;
    }
}

void Merge(std::vector<int>& A, int lo, int mid, int hi) {
    int length_left = mid - lo + 1;
    int length_right = hi - mid;

    std::vector<int> left, right;

    for (int i = 0; i < length_left; i++)
        left[i] = A[lo + i];
    for (int i = 0; i < length_right; i++)
        right[i] = A[mid + i  + 1];

    int i = 0, j = 0, k = lo;
    while (i < length_left && j < length_right) {
        if (left[i] <= right[j])
            A[k++] = left[i++];
        else
            A[k++] = right[j++];
    }

    while (i < length_left)
        A[k++] = left[i++];
    while (j < length_right)
        A[k++] = left[j++];
}

void HybridMergeSort(std::vector<int>& A, int lo, int hi) {
    if (hi - lo + 1 <= treshold) {
        InsertionSort(A, lo, hi);
        return;
    }

    if (lo >= hi)
        return;

    int mid = lo + (hi - lo) / 2;

    HybridMergeSort(A, lo, mid);
    HybridMergeSort(A, mid + 1, hi);
    Merge(A, lo, mid, hi);
}

void PrintArray(const std::vector<int>& A) {
    for (int i = 1; i < A.size(); i++)
        std::cout << A[i] << ' ';
    std::cout << std::endl;
}

int main() {
    std::vector<int> A = {0, 38, 27, 43, 3, 9, 82, 10};

    HybridMergeSort(A, 1, A.size() - 1);
    PrintArray(A);
}
