#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> dist(N, vector<int>(N, INF));
    rep(i, N) dist[i][i] = 0;
    rep(i, M) {
        int A, B, C;
        cin >> A >> B >> C;
        A--;
        B--;
        dist[A][B] = C;
    }

    // Washall Floyd
    ll ans = 0;
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                if (dist[i][j] != INF)
                    ans += dist[i][j];
            }
        }
    }

    cout << ans << endl;

    return 0;
}