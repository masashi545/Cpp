#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {

    // setの使用例
    set<int> s;

    // 要素の追加
    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.insert(4);
    s.insert(-1);

    // ポインタの型
    set<int>::iterator ite;

    // 要素の検索
    ite = s.find(1);
    if (ite == s.end()) {
        cout << "not found" << endl;
    } else {
        cout << "found" << endl;
    }

    ite = s.find(2);
    if (ite == s.end()) {
        cout << "not found" << endl;
    } else {
        cout << "found" << endl;
    }

    // 要素の削除
    s.erase(3);

    // 要素の検索（別の方法）
    if (s.count(3) == 0) {
        cout << "not found" << endl;
    } else {
        cout << "found" << endl;
    }

    // 要素のすべてループする
    for (ite = s.begin(); ite != s.end(); ++ite) {
        cout << *ite << " ";
    }
    cout << endl;

    // mapの使用例
    map<int, const char *> m;

    // 要素の追加
    m.insert(make_pair(1, "ONE"));
    m.insert(make_pair(10, "TEN"));
    m[100] = "HUNDRED";

    // ポインタの型
    map<int, const char *>::iterator ite1;

    // 要素の検索
    ite1 = m.find(1);
    cout << ite1->second << endl;

    ite1 = m.find(2);
    if (ite1 == m.end()) {
        cout << "not found" << endl;
    } else {
        cout << ite1->second << endl;
    }

    // 要素の削除
    s.erase(10);

    // 要素のすべてループする
    for (ite1 = m.begin(); ite1 != m.end(); ++ite1) {
        cout << ite1->first << ": " << ite1->second << endl;
    }

    return 0;
}