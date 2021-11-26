#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<int> S(N);
    rep(i, N) cin >> S[i];

    set<int> a;
    for (int i = 1; i < 143; ++i) {
        for (int j = 1; j < 143; ++j) {
            int s = 4 * i * j + 3 * i + 3 * j;
            if (s <= 1000) {
                a.insert(s);
            }
        }
    }
    int ans = 0;
    rep(i, N) {
        if (!a.count(S[i])) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}