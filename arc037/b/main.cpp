#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int n, m;
vector<vector<int>> E;

bool dfs(int x, int y, vector<bool> &reached) { // yは直前の頂点
    reached[x] = true;
    bool tree = true;
    for (int a : E[x]) {
        if (a == y) { // 直前の頂点なら除外
            continue;
        }
        if (reached[a]) { // すでに訪問したところを訪れる->閉路がある
            tree = false;
        } else if (!dfs(a, x, reached)) { // 隣接する頂点を深さ優先探索
            tree = false;
        }
    }
    return tree;
}

int main() {
    cin >> n >> m;
    E.resize(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        E[u - 1].push_back(v - 1);
        E[v - 1].push_back(u - 1);
    }

    vector<bool> reached(n, false);
    int ans = 0;
    rep(i, n) {
        if (!reached[i]) {
            if (dfs(i, -1, reached)) {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}