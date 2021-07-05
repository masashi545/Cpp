#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;

int fact(int n) {
    if (n == 1) {
        return 1;
    }
    return n * fact(n - 1);
}

int main() {
    int P;
    cin >> P;

    int ans = 0;
    for (int i = 10; i >= 1; --i) {
        int x = fact(i);
        while (P >= x) {
            ans++;
            P -= x;
        }
    }

    cout << ans << endl;

    return 0;
}