#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int x;
    cin >> x;

    if (x < 40) {
        cout << 40 - x << endl;
    } else if (x < 70) {
        cout << 70 - x << endl;
    } else if (x < 90) {
        cout << 90 - x << endl;
    } else {
        cout << "expert" << endl;
    }
    return 0;
}