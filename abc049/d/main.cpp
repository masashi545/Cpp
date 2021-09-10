#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

struct union_find {
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
};

int main() {
    int n, k, l;
    cin >> n >> k >> l;

    union_find road;
    union_find train;
    union_find rt;

    road.init(n);
    train.init(n);
    rt.init(n);

    rep(i, k) {
        int p, q;
        cin >> p >> q;
        road.unite(p - 1, q - 1);
    }
    rep(i, l) {
        int r, s;
        cin >> r >> s;
        train.unite(r - 1, s - 1);
    }

    map<P, int> mp;
    rep(i, n) {
        P p;
        p.first = road.find(i);
        p.second = train.find(i);
        mp[p]++;
    }

    rep(i, n) {
        P p;
        p.first = road.find(i);
        p.second = train.find(i);
        if (i < n - 1) {
            cout << mp[p] << " ";
        } else {
            cout << mp[p] << endl;
        }
    }

    return 0;
}