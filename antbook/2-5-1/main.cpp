#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

// 入力
int n, m;
vector<vector<int>> G(1000);
vector<int> color(1000); // 0:まだ塗られていない、1:黒、-1:白

// 頂点vを色cで塗って矛盾していないかを判定
bool dfs(int v, int c) {
    color[v] = c;
    rep(i, G[v].size()) {
        // 隣接している頂点が同じ色なら、false
        if (color[G[v][i]] == c) {
            return false;
        }
        // 隣接している頂点がまだ塗られていなければ、-cで塗って矛盾していないか判定
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) {
            return false;
        }
    }
    // すべての頂点に色を塗れたらOK
    return true;
}

int main() {
    cin >> n >> m;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    // 連結かどうかわからないので、頂点を順次みていく
    rep(i, n) {
        // まだ塗られていない頂点を起点として、深さ優先探索
        if (color[i] == 0) {
            if (!dfs(i, 1)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}

/*
in:
3 3
0 1
0 2
1 2

out:
No

in:
4 4
0 1
0 3
1 2
2 3

out:
Yes
*/