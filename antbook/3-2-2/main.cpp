#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int p;
    cin >> p;
    vector<int> a(p);
    rep(i, p) cin >> a[i];

    // 書かれている事柄の総数を計算
    set<int> all;
    rep(i, p) {
        all.insert(a[i]);
    }
    int n = all.size();

    // しゃくとり法
    int s = 0, t = 0;
    int num = 0; // 異なる事柄の数
    map<int, int> mp;
    int ans = p;
    while (true) {
        while (t < p && num < n) {
            if (mp[a[t++]]++ == 0) {
                // 新しい事柄が出現したら事柄の数を増やす
                num++;
            }
        }
        if (num < n)
            break;
        ans = min(ans, t - s);
        if (--mp[a[s++]] == 0) {
            // sページを読まないことによって、sの事柄の数が0になるようなら、事柄の数を減らす
            num--;
        }
    }

    cout << ans << endl;
    return 0;
}

/*
in:
5
1 8 8 8 1

out:
2

in:
10
1 2 4 7 2 3 1 7 4 8 

out:
6
*/