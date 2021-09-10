#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

// 入力
int n;
vector<vector<P>> G(100000);
vector<int> color(100000, -1); // -1:まだ塗られていない、 0:白、 1:黒

// 頂点vを色cで塗る
void dfs(int v, int c) {
    color[v] = c;
    rep(i, int(G[v].size())) {
        if (color[G[v][i].first] == -1) {
            if (G[v][i].second % 2 == 0) { // 距離が偶数だったら同じ色で塗る
                dfs(G[v][i].first, c);
            } else { // 距離が奇数だったら違う色で塗る
                dfs(G[v][i].first, 1 - c);
            }
        }
    }
}

int main() {
    cin >> n;
    rep(i, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u - 1].push_back(P(v - 1, w));
        G[v - 1].push_back(P(u - 1, w));
    }

    dfs(0, 0);

    rep(i, n) cout << color[i] << endl;
    return 0;
}