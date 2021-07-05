#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A.at(i) >> B.at(i);
    }

    // (ここで"試合結果の表"の2次元配列を宣言)
    vector<vector<string>> R(N, vector<string>(N, "-"));

    // 試合結果の登録
    for (int i = 0; i < M; i++) {
        R.at(A.at(i) - 1).at(B.at(i) - 1) = "o";
        R.at(B.at(i) - 1).at(A.at(i) - 1) = "x";
    }

    // 出力
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << R.at(i).at(j);
            if (j == N - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
}
