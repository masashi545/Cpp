#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "No" << endl;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cout << "No" << endl;
            cout << i << " * " << n / i << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}

/*
in:
53

out:
Yes

in:
295927

out:
No
541 * 547
*/