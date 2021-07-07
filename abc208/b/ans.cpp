#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;

int main() {
    int P;
    cin >> P;

    int ans = 0;
    int x = 2;
    while (P > 0) {
        ans += P % x;
        P /= x;
        x++;
    }

    /*
    // 10!を求める
    int x = 1;
    for (int i = 0; i <= 10; ++i) {
        x *= i;
    }
    int ans = 0;
    for (int i = 10; i >= 1; --i) {
        ans += P / x; // i!(=x)のコインの枚数
        P %= x;       // 残り
        x /= i;       // x <- (i-1)!
    }*/

    cout << ans << endl;

    return 0;
}