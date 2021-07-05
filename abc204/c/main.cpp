#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> R(M);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        R[x].push_back(y);
    }

    int count = N; // スタートとゴールが同じ場合の数
    for (int i = 0; i < N; i++) {
        for (auto &x : R[i]) {
        }
    }
}