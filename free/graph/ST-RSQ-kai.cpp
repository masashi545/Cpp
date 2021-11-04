#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;
const int DAT_SIZE = (1 << 18) - 1;

// 区間加算対応RSQを実現するセグメント木
vector<ll> datA(DAT_SIZE), datB(DAT_SIZE); // 各節点の値 datA:区間全体に加えられる値、datB:区間に一様ではなく加えられた値の和

// [a,b)にxを加算する
// k:節点のidx
void add(int a, int b, int x, int k, int l, int r) {
    // その節点の区間全体に加算する場合
    if (a <= l && r <= b) {
        datA[k] += x;
    }
    // 区間が重なっていたら
    else if (l < b && a < r) {
        datB[k] += (min(b, r) - max(a, l)) * x; // 重なっている要素分だけxを足す
        add(a, b, x, 2 * k + 1, l, (l + r) / 2);
        add(a, b, x, 2 * k + 2, (l + r) / 2, r);
    }
}

// [a,b)の累積和を求める
// k:注目している節点のidx、この節点が[l,r)を代表した点(ここでは最小値)
int sum(int a, int b, int k, int l, int r) {
    // [a,b)と[l,r)が交差しなければ、0
    if (r <= a || b <= l) {
        return 0;
    }
    // [a,b)が[l,r)を完全に含んでいれば、この節点の値が答え
    if (a <= l && r <= b) {
        return datA[k] * (r - l) + datB[k];
    }

    //　2つの子について再帰的に求め、より小さい方を選択
    ll res = (min(b, r) - max(a, l)) * datA[k];
    res += sum(a, b, 2 * k + 1, l, (l + r) / 2);
    res += sum(a, b, 2 * k + 2, (l + r) / 2, r);
    return res;
}
