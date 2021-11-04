#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

struct seg_tree {

    int m;           // 要素数(葉節点の数)-> ノード数＝2n-1
    vector<int> dat; // 各節点の値

    // n要素で初期化
    void init(int n) {
        m = 1;
        while (m < n)
            m *= 2;

        dat.resize(2 * m - 1, INF);
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
    int n, m;
    cin >> n >> m;
    vector<int> s(m), t(m);
    rep(i, m) {
        cin >> s[i] >> t[i];
    }

    /* dp[i][j] := i番目のSorterまでで、最大値がj番目に移動するような最小の部分列の長さ
     * dp[0][1] = 0
     * dp[0][j] = INF (j>1)
     * dp[i+1][j] = dp[i][j] (t[i]≠j)
     *              min{dp[i][j], min{ dp[i][j']| s[i]<=j'<=t[i]} +1} (t[i]=j)
     * ->
     * dp[j] := 最大値がj番目に移動するような最小の部分列の長さ
     * dp[1]=0, dp[j]=INF(j>1) と初期化
     * dp[t[i]] = min{dp[t[i]], min{dp[j']| s[i]<=j'<=t[i]}+1} と更新
     */

    vector<int> dp(n + 1, INF);
    dp[1] = 0;
    // セグメント木によって、min{dp[j']| s[i]<=j'<=t[i]}の計算を高速化する
    seg_tree st;
    st.init(n);
    st.update(1, 0);
    rep(i, m) {
        int v = min(dp[t[i]], st.query(s[i], t[i] + 1) + 1);
        dp[t[i]] = v;
        st.update(t[i], v);
    }

    cout << dp[n] << endl;
    return 0;
}

/*
in:
40
6
20 30
1 10
10 20
20 30
15 25
30 40

out:
4
*/