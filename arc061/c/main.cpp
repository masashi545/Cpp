#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    ll s;
    cin >> s;
    vector<int> a;
    while (s > 0) {
        a.push_back(s % 10); // 下の位から配列に格納する
        s /= 10;
    }
    int n = a.size();

    ll ans = 0;
    rep(tmp, 1 << (n - 1)) { // 各桁の間に＋を入れるか入れないかの、2^(n-1)通りの全探索
        bitset<9> bs(tmp);

        ll sum = a[0];
        int k = 1;
        rep(i, n - 1) {
            if (bs.test(i)) { // 右に＋があるなら、位をリセットする(1の位にする)
                k = 0;
            }
            sum += a[i + 1] * pow(10, k);
            k++; // 位を一つ上げる
        }
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}