#include <bits/stdc++.h>
using namespace std;

int N, L;

int main() {
    cin >> N >> L;

    // 「味」の総和を求める
    // int sum = (N + 2 * L - 1) * N / 2;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += L + i;
    }

    // 「味」の絶対値の最小値を求める
    // int ate = (N + L - 1 < 0) ? (N + L - 1) : ((L < 0) ? 0 : L);
    int ate = L;
    for (int i = 0; i < N - 1; i++) {
        if (abs(ate) > abs(L + i + 1))
            ate = L + i + 1;
    }

    cout << sum - ate << endl;
}