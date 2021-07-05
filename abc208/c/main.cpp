#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;

int main() {
    int N;
    ll K;
    cin >> N >> K;

    ll x = K / N;
    int y = K % N;

    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(a.begin(), a.end());

    int z = a[y];

    for (auto &c : b) {
        if (c < z) {
            cout << x + 1 << endl;
        } else {
            cout << x << endl;
        }
    }

    return 0;
}