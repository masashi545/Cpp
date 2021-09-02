#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    ll n;
    cin >> n;

    bitset<120> bs(n);

    bool flag = false;
    for (int i = 119; i >= 0; --i) {
        if (flag) {
            if (bs.test(i)) {
                cout << "BA";
            } else {
                cout << "B";
            }
        }

        if (!flag && bs.test(i)) {
            flag = true;
            cout << "A";
        }
    }
    cout << endl;
    return 0;
}