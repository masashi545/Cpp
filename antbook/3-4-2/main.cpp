#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int main() {
    int m, r;
    cin >> m >> r;
    vector<vector<double>> d(m, vector<double>(m, -1));
    rep(i, r) {
        int x, y;
        double w;
        cin >> x >> y >> w;
        d[x][y] = w;
        d[y][x] = w;
    }
    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    vector<int> t(n);
    rep(i, n) cin >> t[i];

    // dp[S][v]..Sの残っている乗車券の集合, v:現在いる頂点
    // この状態に至るまでの最小コスト
    vector<vector<double>> dp(1 << n, vector<double>(m, INF));

    dp[(1 << n) - 1][a] = 0; // 111..11 つまり乗車券が全て残っていて始点にいる初期状態

    double ans = INF;
    for (int S = (1 << n) - 1; S >= 0; --S) {
        ans = min(ans, dp[S][b]);
        rep(v, m) {
            rep(i, n) {
                if (S >> i & 1) { // i番目の乗車券が残っていたら
                    rep(u, m) {
                        if (d[v][u] >= 0) {
                            // 乗車券iを使って、vからuへ移動
                            dp[S & ~(1 << i)][u] = min(dp[S & ~(1 << i)][u], dp[S][v] + d[v][u] / t[i]);
                        }
                    }
                }
            }
        }
    }

    if (ans == INF) {
        cout << "Impossible" << endl;
    } else {
        cout << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}

/*
in:
4 4
0 2 3
0 3 2
1 2 3
1 3 5
1 0
2
3 1

out:
3.667
*/