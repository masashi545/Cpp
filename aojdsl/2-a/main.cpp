#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

vector<int> dat; // 各節点の値
int m;           // 要素数(葉節点の数)-> 総節点数＝2m-1

// n要素で初期化
void init(int n) {
    m = 1;
    while (m < n)
        m *= 2;

    rep(i, 2 * m - 1) {
        dat.push_back(INT_MAX);
    }
}

// k番目(0idx)の値を、aに変更
void update(int k, int a) {
    // 葉の節点
    k += m - 1; // 根(idx[0])から数えて、最も左の葉はidx[n-1]
    dat[k] = a;
    // 登りながら更新
    while (k > 0) {
        k = (k - 1) / 2;                              // 親のidx
        dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]); // 2つの子節点の最小値を格納
    }
}

// [a,b)の最小値を求める
// k:注目している節点のidx、この節点が[l,r)を代表した点(ここでは最小値)
int find(int a, int b, int k, int l, int r) {
    // [a,b)と[l,r)が交差しなければ、INF
    if (r <= a || b <= l) {
        return INT_MAX;
    }
    // [a,b)が[l,r)を完全に含んでいれば、この節点の値が答え
    if (a <= l && r <= b) {
        return dat[k];
    }

    //　2つの子について再帰的に求め、より小さい方を選択
    int vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
    int vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
    return min(vl, vr);
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> com(q), x(q), y(q);
    rep(i, q) cin >> com[i] >> x[i] >> y[i];

    init(n);
    rep(i, q) {
        if (com[i] == 0) {
            update(x[i], y[i]);
        } else {                                 // com == 1
            int ans = find(x[i], y[i], 0, 0, m); // [x,y)の最小値
            cout << min(ans, dat[y[i] + m - 1]) << endl;
        }
    }
}