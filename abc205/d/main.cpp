#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N);
    for (auto &x : A) {
        cin >> x;
    }

    // Aiより小さい正整数で、Ak(k=1.2..i)とは異なるものの個数
    vector<ll> C(N);
    for (int i = 0; i < N; i++) {
        C.at(i) = A.at(i) - i - 1;
    }

    while (Q--) { // Q回の繰り返し
        ll k;
        cin >> k;

        // lower_boundは、二分探索で、ソートされた配列からkey以上で最小のイテレータを返す
        // begin()は配列の先頭、end()は配列の末尾の次の要素を指す
        // key以上の要素がない場合は、end()を返す
        // ここでは、配列Cの中で、k以上で最小の要素のイテレータを求め、先頭のイテレータとの差で要素番号を求めている
        const int idx = lower_bound(C.begin(), C.end(), k) - C.begin();

        if (idx == 0) { // k < C.at(0)
            cout << k << endl;
        } else {
            cout << A.at(idx - 1) + k - C.at(idx - 1) << endl;
        }
    }
    return 0;
}
