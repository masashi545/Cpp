#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

// Union-Find木の実装
vector<int> par;   // 親
vector<int> depth; // 木の深さ

// n要素で初期化
void init(int n) {
    rep(i, n) {
        par.push_back(i);
        depth.push_back(0);
    }
}

// 木の根を求める
int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        par[x] = find(par[x]);
        return par[x];
    }
}

// ｘとｙの属する集合を併合
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) { // 同じ値だったら、既に同じ集合なので併合する必要はない
        return;
    }

    if (depth[x] < depth[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (depth[x] == depth[y]) {
            depth[x]++;
        }
    }
}

// ｘとｙが同じ集合に属するか否か
bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> T(k), X(k), Y(k);
    rep(i, k) cin >> T[i] >> X[i] >> Y[i];

    // x, x + N, x + 2N を、 x-A, x-B, x-C の要素とする
    // x-A...xが種類Aに属しているという状況
    init(n * 3);

    int ans = 0;
    rep(i, k) {
        int t = T[i];
        int x = X[i] - 1;
        int y = Y[i] - 1;

        // 正しくない番号
        if (x < 0 || n <= x || y < 0 || n <= y) {
            ans++;
            continue;
        }

        if (t == 1) {                                   // same(x,y) = trueであるべき
            if (same(x, y + n) || same(x, y + 2 * n)) { // x-Aと、y-Bまたはy-Cが同じ集合に属していたらOUT
                ans++;
            } else {
                unite(x, y);
                unite(x + n, y + n);
                unite(x + 2 * n, y + 2 * n);
            }
        } else if (t == 2) { // same(x,y+n) = trueであるべき
            if (same(x, y) || same(x, y + 2 * n)) {
                ans++;
            } else {
                unite(x, y + n);
                unite(x + n, y + 2 * n);
                unite(x + 2 * n, y);
            }

        } else {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}

/*
in:
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5

out:
3
*/