#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

vector<int> par;   // 親
vector<int> depth; // 木の深さ

// Union-Find木の実装

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
    int n, q;
    cin >> n >> q;
    vector<int> p(q), a(q), b(q);
    rep(i, q) cin >> p[i] >> a[i] >> b[i];

    init(n);

    rep(i, q) {
        if (p[i] == 0) {
            unite(a[i], b[i]);
        } else {
            bool ans = same(a[i], b[i]);
            cout << (ans ? "Yes" : "No") << endl;
        }
    }
    return 0;
}