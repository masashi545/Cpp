#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(n, INF));
    rep(i, m) {
        int s, t;
        cin >> s >> t;
        cin >> d[s][t];
    }

    // dp[S][v]..S:すでに訪れた頂点集合, v:現在いる頂点
    // この状態から、残りの全ての頂点をめぐって頂点0に戻る経路の最小値
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));

    dp[(1 << n) - 1][0] = 0; // 1111..11 つまり全ての頂点を訪れた場合

    for (int S = (1 << n) - 2; S >= 0; --S) {
        rep(v, n) {
            rep(u, n) {
                if (!(S >> u & 1)) { // uにまだ訪れていなかったら更新
                    dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + d[v][u]);
                }
            }
        }
    }

    cout << dp[0][0] << endl;
    return 0;
}

/*
in:
5 8
0 1 3
0 3 4
1 2 5
2 0 4
2 3 5
3 4 3
4 0 7
4 1 6

out:
22
*/