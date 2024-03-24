#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// �������ÿ��������������ڻ���Cache �Ż��㷨��
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
    int n = 1000;  // ����ά��
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

    // ��ʱ��ʼ
    auto start = steady_clock::now();

    int* result = cacheOptimizedInnerProduct(matrix, vector, n);

    // ��ʱ����
    auto stop = steady_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Inner Products (Cache Optimized Algorithm): ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    // ��ӡ����ִ��ʱ��
    cout << "Execution Time: " << duration.count() << " nanoseconds" << endl;

    // �ͷŶ�̬������ڴ�
    delete[] vector;
    delete[] result;
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
