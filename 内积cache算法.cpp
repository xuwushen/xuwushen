#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// 计算矩阵每列与给定向量的内积（Cache 优化算法）
int* cacheOptimizedInnerProduct(int** matrix, int* vector, int n) {
    int* result = new int[n]();

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            result[col] += matrix[row][col] * vector[row];
        }
    }

    return result;
}

int main() {
    int n = 1000;  // 矩阵维度
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = i+j;
        }
    }

    int* vector = new int[1000];
    for (int i = 0; i < n; i++) {
            vector[i] = i+1;
        }

    // 计时开始
    auto start = steady_clock::now();

    int* result = cacheOptimizedInnerProduct(matrix, vector, n);

    // 计时结束
    auto stop = steady_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Inner Products (Cache Optimized Algorithm): ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    // 打印代码执行时间
    cout << "Execution Time: " << duration.count() << " nanoseconds" << endl;

    // 释放动态分配的内存
    delete[] vector;
    delete[] result;
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
