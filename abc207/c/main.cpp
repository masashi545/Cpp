#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, s, t) for (int i = s; i < (t); ++i)
#define rrep(i, s, t) for (int i = s; i >= (t); --i)
#define fora(x, a) for (auto &x : a)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<pair<double, double>> A(N);
    rep(i, 0, N) {
        int t;
        double l, r;
        cin >> t >> l >> r;
        if (t == 2 || t == 4)
            r -= 0.5;
        if (t == 3 || t == 4)
            l += 0.5;
        A[i].first = l;
        A[i].second = r;
    }

    int ans = N * (N - 1) / 2;
    rep(i, 0, N) {
        rep(j, i + 1, N) {
            if (A[i].second < A[j].first || A[j].second < A[i].first)
                // min(A[i].first, A[j].first) < max(A[i].second, A[j].second)
                ans--;
        }
    }
    cout << ans << endl;
    return 0;
}