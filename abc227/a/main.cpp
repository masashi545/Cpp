#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int main() {
    int N, K, A;
    cin >> N >> K >> A;
    cout << (A + K - 2) % N + 1 << endl;
    return 0;
}