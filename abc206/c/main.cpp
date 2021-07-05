#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, s, t) for (int i = s; i < (t); ++i)
#define rrep(i, s, t) for (int i = s; i >= (t); --i)
#define fora(x, a) for (auto &x : a)
using ll = long long;
using P = pair<int, int>;
/*
int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    map<int, ll> mp;
    ll ans = 0;
    rep(j, 0, n) {
        ans += j - mp[a[j]]; // a[j]を考えて、それまでのj個の要素の中で、a[j]と同じものを取り除く
        mp[a[j]]++;          // a[j]の個数を、map<a[j],count>で保持する
    }

    cout << ans << endl;
    return 0;
}*/

int main() {
    ll n;
    cin >> n;

    map<int, ll> mp;
    rep(i, 0, n) {
        int a;
        cin >> a;
        mp[a]++;
    }

    // 組み合わせで考える
    ll ans = n * (n - 1) / 2; // すべての場合の組み合わせ
    fora(a, mp) {
        ll m = a.second;
        ans -= m * (m - 1) / 2; // mコ重複しているとすると、その組み合わせは、m(m-1)/2
    }

    cout << ans << endl;
    return 0;
}