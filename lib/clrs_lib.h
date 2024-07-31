#pragma once

#include <type_traits>
#include <functional>
#include <iostream>
#include <vector>
#include <chrono>

void FillRandVec(std::vector<int>& vec, int upper_bound, bool zero_indexed);

// Helper struct to handle void return type
template<typename Func, typename... Args>
struct IsVoidReturn : std::is_void<std::invoke_result_t<Func, Args...>> {};

// Function template to measure the execution time of another function
template<typename Func, typename... Args>
auto MeasureTime(Func&& func, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();

    if constexpr (IsVoidReturn<Func, Args...>::value) {
        std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;
    } else {
        auto result = std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;
        return result;
    }
}