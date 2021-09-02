#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, l, p;
    cin >> n >> l >> p;
    vector<int> a(n + 1), b(n + 1);
    rep(i, n) cin >> a[i] >> b[i];
    a[n] = l;
    b[n] = 0;

    priority_queue<int> que;

    int ans = 0;  // 補給回数
    int pos = 0;  // 現在位置
    int tank = p; // タンクに残るガゾリン量

    // 各ガソリンスタンドの地点まで行く際に、途中でタンクが空になったら、通過したスタンドで補給する
    rep(i, n) {
        int d = a[i] - pos; // 今回移動する距離

        while (tank - d < 0) { // タンクが空になったら補給する
            if (que.empty()) { // 補給できるスタンドがないのにタンクが0になってしまったら、OUT
                cout << -1 << endl;
                return 0;
            }
            tank += que.top(); // 通過したスタンドで最も補給量が大きいもので補給する
            que.pop();
            ans++;
        }

        tank -= d; // 移動した分ガソリンを使う
        pos = a[i];
        que.push(b[i]);
    }

    cout << ans << endl;
    return 0;
}

/*
in:
4
25
10
10 10
14 5
20 2
21 4

out:
2
*/

int main1() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> que; // 小さい順に取り出す
    rep(i, n) {
        int l;
        cin >> l;
        que.push(l);
    }

    ll ans = 0;

    // 板が1枚になるまで
    while (que.size() > 1) {
        int l1, l2;
        l1 = que.top();
        que.pop();
        l2 = que.top();
        que.pop();

        ans += l1 + l2;
        que.push(l1 + l2);
    }

    cout << ans << endl;
    return 0;
}

/*
in:
3
8 5 8

out:
34
*/