#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> R(N);
    rep(i, M) {
        int x, y;
        cin >> x >> y;
        R[x - 1].push_back(y - 1);
    }

    int count = 0;
    rep(i, N) {
        rep(i, N) {
                }
    }
}