#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// ����ۼӵ�ƽ���㷨
int sumSequential(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n = 1000000; // �����С
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1; // �������
    }

    // ��ʱ��ʼ
    auto start = high_resolution_clock::now();

    int sum = sumSequential(arr, n);

    // ��ʱ����
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sum: " << sum << endl;
    cout << "Execution Time (Sequential Sum): " << duration.count() << " microseconds" << endl;

    delete[] arr;
    return 0;
}
