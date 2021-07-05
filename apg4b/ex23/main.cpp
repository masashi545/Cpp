#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<int, int> times; // key(整数)->value(出現回数)

    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        times[A]++; // 入力整数Aをkey、出現回数をvalueとして保存する。
        /* こっちの方が正確かも...
        if (times.count(A)) { 
            times.at(A)++; // 既に含まれているなら、valueをインクリメント
        } else {
            times[A] = 1; // 含まれていないなら、(A->1)を追加
        } */
    }

    pair<int, int> mode(0, 0); // 最頻値とその出現回数を保持する変数

    for (auto p : times) {
        if (p.second > mode.second) { // 出現回数について比較
            mode = p;
        }
    }

    cout << mode.first << " " << mode.second << endl;
}
