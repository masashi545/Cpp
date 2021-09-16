#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n;
    string s;
    cin >> n >> s;
    if (s[n - 1] == 'o') {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}