#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    rep(i, n) {
        cin >> c[i];
    }

    map<int, int> mp; // 種類をKey、その種類のキャンディの個数をValueとする
    rep(i, k) {
        mp[c[i]]++;
    }
    int ans = mp.size(); // 0~k-1

    for (int i = k; i < n; i++) {
        mp[c[i]]++;     // i番目のキャンディを1つ追加
        mp[c[i - k]]--; // i-k番目のキャンディを1つ削除
        if (mp[c[i - k]] == 0) {
            mp.erase(c[i - k]); // i-k番目のキャンディの個数が0になったら、要素自体を削除
        }
        ans = max(ans, int(mp.size()));
    }

    cout << ans << endl;
    return 0;
}