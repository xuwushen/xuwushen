#include<iostream>
using namespace std;

struct M {
    int mlike[50];
    int marry;
    int point;
    int soul;
};

struct W {
    int wlike[50];
    int marry;
    int point;
    int soul;
};

W w[50];
M m[50];

int Compared(int a, int b, int value, int N) {
    for (int i = 1; i <= N; i++) {
        if (w[value].wlike[i] == a)
            return 1;
        if (w[value].wlike[i] == b)
            return 0;
    }
    return -1;
}

void marry(int N) {
    while (true) {
        int end = 0;
        for (int i = 1; i <= N; i++) {
            if (m[i].marry != 0)
                continue; // 跳过已匹配的男性

            int value = m[i].mlike[m[i].point];
            if (w[value].marry == 0) {
                m[i].soul = value;
                m[i].marry = 1;
                w[value].soul = i;
                w[value].marry = 1;
            }
            else {
                int soul_old = w[value].soul;
                if (Compared(i, soul_old, value, N) == 1) {
                    m[soul_old].marry = 0;
                    m[soul_old].point++;
                    m[i].soul = value;
                    m[i].marry = 1;
                    w[value].soul = i;
                   
                }
                else {
                    m[i].point++;
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            if (m[i].marry == 1)
                end++;
        }

        if (end == N)
            break;
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> m[i].mlike[j];
            m[i].marry = 0;
            m[i].point = 1;
            m[i].soul = -1;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> w[i].wlike[j];
            w[i].marry = 0;
            w[i].point = 1;
            w[i].soul = -1;
        }
    }

    marry(N);

    for (int k = 1; k <= N; k++) {
        cout << m[k].soul<<" ";
    }

    return 0;
}
