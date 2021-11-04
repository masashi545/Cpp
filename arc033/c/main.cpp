#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

const int ST_SIZE = (1 << 19) - 1;

struct seg_tree {

    vector<vector<int>> dat; // 各節点の値

    void init(int k, int l, int r) {
        if (r - l == 1) {
            dat[k].push_back(INF);
        } else {
            int lch = 2 * k + 1;
            int rch = 2 * k + 2;
            init(lch, l, (l + r) / 2);
            init(rch, (l + r) / 2, r);

            dat[k].resize(r - l);
            merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(), dat[k].begin());
        }
    }
    void init(int n) {
        dat.resize(ST_SIZE);
        init(0, 0, n);
    }

    // k番目の要素(葉)の値を、aに変更
    void update(int k, int a) {
        // 葉の節点
        k += m - 1; // 根(idx[0])から数えて、最も左の葉はidx[n-1]
        dat[k] = a;
        // 登りながら更新
        while (k > 0) {
            k = (k - 1) / 2; // 親のidx
            // 親と子の関にによる更新(RMQの場合)
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]); // 2つの子節点の最小値を格納
        }
    }

    // [a,b)の最小値を求める
    // k:注目している節点のidx、この節点が[l,r)を代表した点(ここでは最小値)
    int query(int a, int b, int k, int l, int r) {
        // [a,b)と[l,r)が交差しなければ、INF
        if (r <= a || b <= l) {
            return INF;
        }
        // [a,b)が[l,r)を完全に含んでいれば、この節点の値が答え
        if (a <= l && r <= b) {
            return dat[k];
        }

        //　2つの子について再帰的に求め、より小さい方を選択
        int vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
    int query(int a, int b) {
        return query(a, b, 0, 0, m);
    }
};

int main() {
    int q;
    cin >> q;
    vector<int> t(q), x(q);
    rep(i, q) cin >> t[i] >> x[i];

    seg_tree st;
    st.init(q);

    rep(i, q) {
        if (t[i] == 1) {

        } else { // t[i] == 2
        }
    }
    return 0;
}