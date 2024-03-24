#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// �������Ż��㷨����·��ʽ�ۼӣ�
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
    int n = 1000000; // �����С
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1; // �������
    }

    // ��ʱ��ʼ
    auto start = high_resolution_clock::now();

    int sum = sumSuperScalar(arr, n);

    // ��ʱ����
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sum: " << sum << endl;
    cout << "Execution Time (Super Scalar Sum): " << duration.count() << " microseconds" << endl;

    delete[] arr;
    return 0;
}
