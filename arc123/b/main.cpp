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
    vector<int> A(n), B(n), C(n);
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> B[i];
    rep(i, n) cin >> C[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    int ans = 0;
    while (A.size() > 0 && B.size() > 0 && C.size() > 0) {
        int c = C[C.size() - 1];
        C.pop_back();
        int b = B[B.size() - 1];
        B.pop_back();
        int a = A[A.size() - 1];
        A.pop_back();

        while (b >= c) {
            if (B.size() == 0) {
                cout << ans << endl;
                return 0;
            }
            b = B[B.size() - 1];
            B.pop_back();
        }
        while (a >= b) {
            if (A.size() == 0) {
                cout << ans << endl;
                return 0;
            }
            a = A[A.size() - 1];
            A.pop_back();
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}