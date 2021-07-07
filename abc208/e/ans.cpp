#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    ll N, K;
    cin >> N >> K;

    vector<int> ds; // Nの各桁を入れる配列
    while (N > 0) {
        ds.push_back(N % 10);
        N /= 10;
    }
    reverse(ds.begin(), ds.end()); // 上位の桁から調べれるように

    map<ll, ll> dp;    // first:積、second:その積になる場合の数
    for (int d : ds) { // d:各桁の値
        map<ll, ll> pre;
        // preからdpに遷移させる
        swap(dp, pre);
        for (auto p : pre) {
            rep(i, 10) { // i:今の桁の数
                dp[p.first * i] += p.second;
            }
        }
    }

    return 0;
}