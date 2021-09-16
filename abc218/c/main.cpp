#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> Gs, Gt;
    P sx = P(n - 1, 0);
    P sy = P(n - 1, 0);
    rep(i, n) {
        vector<char> x(n);
        bool bx = false;
        rep(j, n) {
            cin >> x[j];
            if (x[j] == '#') {
                bx = true;
                sy.first = min(sy.first, j);
                sy.second = max(sy.second, j);
            }
        }
        if (bx) {
            sx.first = min(sx.first, i);
            sx.second = max(sx.second, i);
        }
        Gs.push_back(x);
    }
    P tx = P(n - 1, 0);
    P ty = P(n - 1, 0);
    rep(i, n) {
        vector<char> x(n);
        bool bx = false;
        rep(j, n) {
            cin >> x[j];
            if (x[j] == '#') {
                bx = true;
                ty.first = min(ty.first, j);
                ty.second = max(ty.second, j);
            }
        }
        if (bx) {
            tx.first = min(tx.first, i);
            tx.second = max(tx.second, i);
        }
        Gt.push_back(x);
    }

    P ssize = P(sx.second - sx.first + 1, sy.second - sy.first + 1);
    P tsize = P(tx.second - tx.first + 1, ty.second - ty.first + 1);
    // cout << ssize.first << " " << ssize.second << endl;
    // cout << tsize.first << " " << tsize.second << endl;

    vector<vector<char>> S(ssize.first, vector<char>(ssize.second));
    vector<vector<char>> T(tsize.first, vector<char>(tsize.second));

    rep(i, ssize.first) {
        int k = sx.first + i;
        rep(j, ssize.second) {
            int l = sy.first + j;
            S[i][j] = Gs[k][l];
        }
    }
    rep(i, tsize.first) {
        int k = tx.first + i;
        rep(j, tsize.second) {
            int l = ty.first + j;
            T[i][j] = Gt[k][l];
        }
    }

    // SとTが一致するか調べる
    if (ssize == tsize) {
        // 回転なし
        bool ans = true;
        rep(i, ssize.first) {
            rep(j, ssize.second) {
                if (S[i][j] != T[i][j]) {
                    ans = false;
                    break;
                }
            }
            if (!ans)
                break;
        }
        if (ans) {
            cout << "Yes" << endl;
            return 0;
        }

        // 180度回転
        ans = true;
        rep(i, ssize.first) {
            rep(j, ssize.second) {
                if (S[i][j] != T[ssize.first - i - 1][ssize.second - j - 1]) {
                    ans = false;
                    break;
                }
            }
            if (!ans)
                break;
        }
        if (ans) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    if (ssize.first == tsize.second && ssize.second == tsize.first) {
        // 90度回転
        bool ans = true;
        rep(i, ssize.first) {
            rep(j, ssize.second) {
                if (S[i][j] != T[ssize.second - j - 1][i]) {
                    ans = false;
                    break;
                }
            }
            if (!ans)
                break;
        }
        if (ans) {
            cout << "Yes" << endl;
            return 0;
        }

        // 270度回転
        ans = true;
        rep(i, ssize.first) {
            rep(j, ssize.second) {
                if (S[i][j] != T[j][ssize.first - i - 1]) {
                    ans = false;
                    break;
                }
            }
            if (!ans)
                break;
        }
        if (ans) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}