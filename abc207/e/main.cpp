#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;

const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), sum(N + 1); // sum[i] : A1~Aiの総和 (sum[0] = 0)
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum[i + 1] = sum[i] + A[i];
    }

    // ｘを格納する行列
    vector<vector<int>> idx(N + 1, vector<int>(N + 1, -1)); // -1で初期化
    for (int j = 0; j <) {
    }
    // dp[i][j] : A1~Aiをｊ個に分割する場合の数
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0)); // dp[0][0]~dp[N][N]
    dp[0][0] = 1;
    for (int i = 1; i <= N + 1; i++) {
        for (int j = 1; j <= N + 1; j++) {
            int x = idx[i][j];
            if (x != -1) {                                  // xがあれば、
                dp[i][j] = (dp[x][j - 1] + dp[x][j]) % MOD; // 遷移
            }
        }
    }
    int ans = sum(dp[N]) % MOD;

    return 0;
}