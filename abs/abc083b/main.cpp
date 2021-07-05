#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    int sum_all = 0;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        sum += i / 10000;
        sum += (i % 10000) / 1000;
        sum += (i % 1000) / 100;
        sum += (i % 100) / 10;
        sum += i % 10;

        if (A <= sum && sum <= B)
            sum_all += i;
    }

    cout << sum_all << endl;
}