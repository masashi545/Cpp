#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int n, W;
vector<int> w, v;
vector<vector<int>> memo; //メモ化テーブル

int search(int i, int u) {
    if (memo[i][u] >= 0) { // 既に調べたことがあるならメモしておいた結果を再利用
        return memo[i][u];
    }

    int ans;
    if (i == n) { // 品物は残っていないので、得られる価値なし
        ans = 0;
    } else if (u < w[i]) { // この品物は入らないので、次以降の品物について調べる
        ans = search(i + 1, u);
    } else { // この品物を入れない場合と、入れる場合でコストが大きくなる方を選ぶ
        ans = max(search(i + 1, u), search(i + 1, u - w[i]) + v[i]);
    }
    // 結果をメモ
    memo[i][u] = ans;
    return ans;
}

int main() {
    cin >> n;
    w.resize(n);
    v.resize(n);
    rep(i, n) cin >> w[i] >> v[i];
    cin >> W;

    memo.assign(n + 1, vector<int>(W + 1, -1)); // メモ化テーブルの初期化
    cout << search(0, W) << endl;

    return 0;
}

/*
in:
4
2 3
1 2
3 4
2 2
5
out:
7
*/