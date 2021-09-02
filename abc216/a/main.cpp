#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    double x;
    int y;
    cin >> x;

    y = x;
    // cout << x << endl;
    cout << y;

    if (x - y <= 0.2) {
        cout << "-";
    } else if (0.7 <= x - y) {
        cout << "+";
    }

    cout << endl;
    return 0;
}