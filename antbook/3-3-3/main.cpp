#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;
const int DAT_SIZE = (1 << 18) - 1;

// 区間加算対応RMQを実現するセグメント木
vector<ll> data(DAT_SIZE, 0), datb(DAT_SIZE, 0); // 各節点の値 data:区間全体に加えられる値、datb:区間に一様ではなく加えられた値の和

// [a,b)にxを加算する
// k:節点のidx
void add(int a, int b, int x, int k, int l, int r) {
    // その節点の区間全体に加算する場合
    if (a <= l && r <= b) {
        data[k] += x;
    }
    // 区間が重なっていたら
    else if (l < b && a < r) {
        datb[k] += (min(b, r) - max(a, l)) * x; // 重なっている要素分だけxを足す
        add(a, b, x, 2 * k + 1, l, (l + r) / 2);
        add(a, b, x, 2 * k + 2, (l + r) / 2, r);
    }
}

// [a,b)の累積和を求める
// k:注目している節点のidx、この節点が[l,r)を代表した点(ここでは最小値)
ll sum(int a, int b, int k, int l, int r) {
    // [a,b)と[l,r)が交差しなければ、0
    if (r <= a || b <= l) {
        return 0;
    }
    // [a,b)が[l,r)を完全に含んでいれば、この節点の値が答え
    if (a <= l && r <= b) {
        return data[k] * (r - l) + datb[k];
    }

    //　2つの子について再帰的に求め、より小さい方を選択
    ll res = (min(b, r) - max(a, l)) * data[k];
    res += sum(a, b, 2 * k + 1, l, (l + r) / 2);
    res += sum(a, b, 2 * k + 2, (l + r) / 2, r);
    return res;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    vector<int> T(q), L(q), R(q), X(q);
    rep(i, q) {
        cin >> T[i] >> L[i] >> R[i];
        if (T[i] == 0)
            cin >> X[i];
    }

    // 木の初期化
    rep(i, n) {
        add(i, i + 1, A[i], 0, 0, n);
    }

    rep(i, q) {
        if (T[i] == 0) {
            add(L[i], R[i] + 1, X[i], 0, 0, n);
        } else { // T[i] == 1
            cout << sum(L[i], R[i] + 1, 0, 0, n) << endl;
        }
    }
    return 0;
}

/*
in:
8 3
5 3 7 9 6 4 1 2
0 0 4 1
1 0 7
1 0 3

out:
42
28
*/