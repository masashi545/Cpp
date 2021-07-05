#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> data(5);
    for (int i = 0; i < 5; i++) {
        cin >> data.at(i);
    }

    // dataの中で隣り合う等しい要素が存在するなら"YES"を出力し、そうでなければ"NO"を出力する
    string out = "NO";
    for (int i = 1; i < 5; i++) {
        if (data.at(i - 1) == data.at(i)) {
            out = "YES";
            break;
        }
    }
    cout << out << endl;
}
