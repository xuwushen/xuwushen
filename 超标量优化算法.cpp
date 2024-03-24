#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// 超标量优化算法（两路链式累加）
int sumSuperScalar(int* arr, int n) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i += 2) {
        sum1 += arr[i];
        if (i + 1 < n) {
            sum2 += arr[i + 1];
        }
    }
    return sum1 + sum2;
}

int main() {
    int n = 1000000; // 数组大小
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1; // 填充数组
    }

    // 计时开始
    auto start = high_resolution_clock::now();

    int sum = sumSuperScalar(arr, n);

    // 计时结束
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sum: " << sum << endl;
    cout << "Execution Time (Super Scalar Sum): " << duration.count() << " microseconds" << endl;

    delete[] arr;
    return 0;
}
