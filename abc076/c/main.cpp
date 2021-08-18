#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    vector<string> ans;

    rep(l, n - m + 1) { // tを入れることができる範囲を後ろからループ

        // 条件1を満たせるか
        bool clear = true;
        rep(i, m) {
            if (s[l + i] != '?' and s[l + i] != t[i]) {
                clear = false;
                break;
            }
        }

        // 条件2を満たす文字列を作成
        if (clear) {
            string res;
            rep(i, n) {
                //　tを入れる
                if (i == l) {
                    rep(j, m) {
                        res += t[j];
                    }
                    i += m - 1;
                }
                // 'a'を入れる
                else if (s[i] == '?') {
                    res += 'a';
                }
                // sの英文字部分をそのまま入れる
                else {
                    res += s[i];
                }
            }
            ans.push_back(res);
        }
    }

    if (ans.size() == 0) {
        cout << "UNRESTORABLE" << endl;
    } else {
        sort(ans.begin(), ans.end());
        cout << ans[0] << endl;
    }
    return 0;
}