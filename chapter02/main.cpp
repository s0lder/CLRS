#include <iostream>
#include <random>
#include <chrono>
#include <array>

const int kArrSize = 8;

void AddBinaryIntegers(std::array<int, kArrSize>& A, std::array<int, kArrSize>& B, std::array<int, kArrSize + 1>& C) {
    int carry = 0;
    for (int i = kArrSize - 1; i >= 0; i--) {
        int sum = A[i] + B[i] + carry;
        C[i + 1] = sum % 2;
        carry = sum / 2;
        /*
        if (sum > 1)
            carry = 1;
        else
            carry = 0;
        */
    }
    C[0] = carry;
}

void SelectionSort(std::array<int, kArrSize>& arr) {
    for (int i = 0; i < kArrSize - 1; i++) {
        int min = i;

        for (int j = i + 1; j < kArrSize; j++)
            if (arr[j] < arr[min])
                min = j;
        
        std::swap(arr[i], arr[min]);
    }
}

void InsertionSort(std::array<int, kArrSize>& arr) {
    for (int i = 1; i < kArrSize; i++) {
        int key = arr[i];

        // Insert arr[i] into the sorted subarray arr[0 : i - 1]
        int j = i - 1;

        // arr[j] < key for descending order
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        
        arr[j + 1] = key;

    }
}

int main() {
    std::array<int, kArrSize> arr;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist1000(1, 1000);

    
    for (int i = 0; i < 10; i++ && std::cout << std::endl << std::endl) {
        for (int i = 0; i < kArrSize; i++)
            arr[i] = dist1000(rng);
        SelectionSort(arr);
        for (int elem : arr)
            std::cout << elem << ' ';

        int sorted = 1;
        for (int i = 1; i < kArrSize; i++)
            if (arr[i - 1] > arr[i])
                sorted = 0;
        
        if (sorted)
            std::cout << "YES";
        else
            std::cout << "NO";
    }
    /*
        auto t1 = std::chrono::high_resolution_clock::now();
        InsertionSort(arr);
        auto t2 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> ms_double = t2 - t1;

        std::cout << "took " << ms_double.count() / 1000 << " s" << std::endl;
    

        std::uniform_int_distribution<std::mt19937::result_type> dist0_1(0, 1);
    */

    return 0;
}