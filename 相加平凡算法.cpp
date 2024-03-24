#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// 逐个累加的平凡算法
int sumSequential(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n = 1000000; // 数组大小
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1; // 填充数组
    }

    // 计时开始
    auto start = high_resolution_clock::now();

    int sum = sumSequential(arr, n);

    // 计时结束
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sum: " << sum << endl;
    cout << "Execution Time (Sequential Sum): " << duration.count() << " microseconds" << endl;

    delete[] arr;
    return 0;
}
