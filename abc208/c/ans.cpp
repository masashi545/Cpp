#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    ll K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    vector<ll> ans(N, K / N); // とりあえずみんなに、K/N配る
    K %= N;                   // 配った余り

    vector<P> p(N);
    for (int i = 0; i < N; ++i) {
        p[i] = P(a[i], i);
    }
    sort(p.begin(), p.end()); // 第一要素(国民番号)でソートされる

    for (int i = 0; i < K; ++i) { // aの値が小さい順に、K番目までの人にもう一つずつ配る
        ans[p[i].second]++;       // 第二要素が何人目かを表している
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << endl;
    }

    /*
    vector<int> p(N);
    iota(p.begin(), p.end(), 0);
    // rep(i,n) p[i] = i; と同じ
    sort(p.begin(), p.end(), [&](int i, int j) {
        return a[i] < a[j];  // aの値(国民番号)にしたがってソート
    });
    rep(i, k) ans[p[i]]++; 
    */

    return 0;
}