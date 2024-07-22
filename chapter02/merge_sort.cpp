#include <iostream>
#include <vector>
#include <random>
#include <chrono>

void Merge(std::vector<int>& A, int p, int q, int r) {
    int length_left = q - p + 1;
    int length_right = r - q;

    std::vector<int> L(length_left, 0), R(length_right, 0);

    for (int i = 0; i < length_left; i++)
        L[i] = A[p + i];
    for (int i = 0; i < length_right; i++)
        R[i] = A[q + i + 1];
    
    int i = 0, j = 0, k = p;
    while (i < length_left && j < length_right) {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while (i < length_left)
        A[k++] = L[i++];
    while (j < length_right)
        A[k++] = R[j++];
}

void MergeSort(std::vector<int>& A, int p, int r) {
    if (p >= r)
        return;

    int q = (p + r) / 2;
    MergeSort(A, p, q);
    MergeSort(A, q + 1, r);
    Merge(A, p, q, r);
}

int main() {
    std::vector<int> A(1, 0);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> udist(1, 10);

    for (int i = 0; i < 10; i++) {
        A.push_back(udist(rng));
        std::cout << A[i + 1] << ' ';
    }
    std::cout << std::endl;

    int p = 1, r = A.size() - 1;

    auto t1 = std::chrono::high_resolution_clock::now();
    MergeSort(A, p, r);
    auto t2 = std::chrono::high_resolution_clock::now();

    bool flag = true;
    for (int i = 2; i <= r && flag; i++)
        if (A[i - 1] > A[i])
            flag = false;

    std::cout << flag << std::endl;

    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    std::cout << "sorted in " << ms_double.count() / 1000 << " s" << std::endl;

    return 0;
}