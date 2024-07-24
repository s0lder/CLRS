#include <iostream>
#include <vector>
#include <random>

int MergeAndCount(std::vector<int>& arr, int lo, int mid, int hi) {
    int left_length = mid - lo + 1;
    int right_length = hi - mid;
    int counter = 0;

    std::vector<int> left(left_length), right(right_length);
    for (int i = 0; i < left_length; i++)
        left[i] = arr[lo + i];
    for (int i = 0; i < right_length; i++)
        right[i] = arr[mid + i + 1];

    int i = 0, j = 0, k = lo;
    while (i < left_length && j < right_length) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            counter += left_length - i;
        }
    }

    while (i < left_length)
        arr[k++] = left[i++];
    while (j < right_length)
        arr[k++] = right[j++];

    return counter;
}

// O(n * lg(n))
int SortAndCount(std::vector<int>& arr, int lo, int hi) {
    if (lo >= hi)
        return 0;
    
    int mid = lo + (hi - lo) / 2;
    int counter = 0;

    counter += SortAndCount(arr, lo, mid);
    counter += SortAndCount(arr, mid + 1, hi);
    counter += MergeAndCount(arr, lo, mid, hi);

    return counter;
}

// O(n^2)
int NaiveCount(const std::vector<int>& arr) {
    int ans = 0;

    for (int i = 1; i < arr.size(); i++)
        for (int j = i + 1; j < arr.size(); j++)
            if (arr[i] > arr[j] && i < j)
                ans++;

    return ans;
}

int main() {
    const int upper_bound = 1000;
    const int kArrSize = 100;

    std::vector<int> arr(kArrSize + 1);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> rdist(1, upper_bound);

    for (int i = 1; i <= kArrSize; i++)
        arr[i] = rdist(rng);

    // int naive_counter = NaiveCount(arr);
    int fast_counter = SortAndCount(arr, 1, kArrSize);

    std::cout << "Number of inversions " << fast_counter << std::endl;

    return 0;
}