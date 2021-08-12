#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

// 部分和問題
int n, k;
vector<int> a;

bool dfs(int i, int sum) {
    // 合計が、kを超えたら打ち切り
    if (sum > k) {
        return false;
    }
    // 配列全てを検討した
    if (i == n) {
        return (sum == k);
    }
    // a[i]を採用しない場合を探索
    if (dfs(i + 1, sum)) {
        return true;
    }
    // a[i]を採用する場合を探索
    if (dfs(i + 1, sum + a[i])) {
        return true;
    }

    return false;
}

int main() {
    cin >> n >> k;
    rep(i, n) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    if (dfs(0, 0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

/*
in:
4
13
1 2 4 7
out:
Yes

in:
4
15
1 2 4 7
out:
No
*/