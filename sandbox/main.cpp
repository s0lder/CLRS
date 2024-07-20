#include <iostream>
#include <random>
#include <chrono>
#include <array>

const int kArrSize = 100000;

void AddBinaryIntegersDiv(const std::array<int, kArrSize>& A, const std::array<int, kArrSize>& B, std::array<int, kArrSize + 1>& C) {
    int carry = 0;
    for (int i = kArrSize - 1; i >= 0; --i) {
        int sum = A[i] + B[i] + carry;
        C[i + 1] = sum % 2;
        carry = sum / 2;
    }
    C[0] = carry;
}

void AddBinaryIntegersComp(const std::array<int, kArrSize>& A, const std::array<int, kArrSize>& B, std::array<int, kArrSize + 1>& C) {
    int carry = 0;
    for (int i = kArrSize - 1; i >= 0; --i) {
        int sum = A[i] + B[i] + carry;
        C[i + 1] = sum % 2;
        carry = sum > 1 ? 1 : 0;
    }
    C[0] = carry;
}

int main() {
    std::array<int, kArrSize> A;
    std::array<int, kArrSize> B;
    std::array<int, kArrSize + 1> C1 = {0};
    std::array<int, kArrSize + 1> C2 = {0};

    // Initialize random number generator
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist0_1(0, 1);

    // Fill arrays A and B with random binary values
    for (int i = 0; i < kArrSize; ++i) {
        A[i] = dist0_1(rng);
        B[i] = dist0_1(rng);
    }

    // Measure the time taken by AddBinaryIntegersDiv
    auto t1 = std::chrono::high_resolution_clock::now();
    AddBinaryIntegersDiv(A, B, C1);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double_div = t2 - t1;

    // Measure the time taken by AddBinaryIntegersComp
    auto t3 = std::chrono::high_resolution_clock::now();
    AddBinaryIntegersComp(A, B, C2);
    auto t4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double_comp = t4 - t3;

    std::cout << "Time taken by division method: " << ms_double_div.count() << " ms" << std::endl;
    std::cout << "Time taken by comparison method: " << ms_double_comp.count() << " ms" << std::endl;

    return 0;
}