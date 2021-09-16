#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

// ax + by = gcd(a,b) を満たす x,yを求める
P extgcd(int a, int b) {
    if (b == 0) {
        return P(1, 0);
    }
    P p = extgcd(b, a % b);
    swap(p.first, p.second);
    p.second -= (a / b) * p.first;
    return p;
}

int main() {
    int a, b;
    cin >> a >> b;

    P p = extgcd(a, b);

    cout << p.first << " " << p.second << endl;
    return 0;
}