#include <bits/stdc++.h>
using namespace std;

map<char, int> int_env;         // 整数の変数と値の関係を保持
map<char, vector<int>> vec_env; // 配列の変数と値の関係を保持

// char->int変換
int ctoi(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return 0;
}

// 整数を読み込む
int int_in() {
    int res; // 返り値となるint値

    char x;
    cin >> x;
    if (isdigit(x)) { // 入力xが整数の場合
        res = ctoi(x);
    } else { // 入力xが変数の場合
        if (int_env.count(x)) {
            res = int_env.at(x);
        } else {
            cout << "error";
        }
    }

    return res;
}

// <int式>の整数値を返す
int int_op() {
    int res = int_in(); // <int式>の整数を保持

    while (true) {
        char op;
        cin >> op;
        if (op == ';') { // セミコロンで終了
            break;
        } else if (op == '+') {
            res += int_in();
        } else if (op == '-') {
            res -= int_in();
        } else {
            cout << "error";
            break;
        }
    }

    return res;
}

// 配列を読み込む
vector<int> vec_in() {
    vector<int> res; // 返り値となる配列

    char y; // 一文字目は、「[」または変数の可能性
    cin >> y;
    if (y == '[') { // 配列の場合
        res = {int_in()};

        while (true) {
            char symbol;
            cin >> symbol;
            if (symbol == ']') {
                break;
            } else if (symbol == ',') {
                res.push_back(int_in());
            }
        }

    } else if (vec_env.count(y)) { // 変数の場合
        return vec_env.at(y);
    }
    return res;
}

// 配列に対して＋演算子をオーバーロード
vector<int> operator+(vector<int> a, vector<int> b) {
    int n = a.size();
    vector<int> ret(n);
    for (int i = 0; i < n; i++) {
        ret.at(i) = a.at(i) + b.at(i);
    }
    return ret;
}

// 配列に対して-演算子をオーバーロード
vector<int> operator-(vector<int> a, vector<int> b) {
    int n = a.size();
    vector<int> ret(n);
    for (int i = 0; i < n; i++) {
        ret.at(i) = a.at(i) - b.at(i);
    }
    return ret;
}

vector<int> vec_op() {
    vector<int> res = vec_in(); // <vec式> の配列を保持

    while (true) {
        char op;
        cin >> op;
        if (op == ';') { // セミコロンで終了
            break;
        } else if (op == '+') {
            res = res + vec_in();
        } else if (op == '-') {
            res = res - vec_in();
        } else {
            cout << "error";
            break;
        }
    }
    return res;
}

// int値を出力
void print_int(int x) {
    cout << x << endl;
}

// 問題文の形式でvec値を出力
void print_vec(vector<int> vec) {
    cout << "[ ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }
    cout << "]" << endl;
}

int main() {
    int N;
    cin >> N;

    string symbol; // 「=」や「;」を、保持しておく。

    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "int") {
            char var;
            cin >> var >> symbol;
            int_env[var] = int_op(); // 整数の変数の宣言

        } else if (cmd == "print_int") {
            int out = int_op();
            print_int(out);

        } else if (cmd == "vec") {
            char var;
            cin >> var >> symbol;
            vec_env[var] = vec_op(); // 配列の変数の宣言

        } else if (cmd == "print_vec") {
            vector<int> out = vec_op();
            print_vec(out);

        } else {
            cout << "error";
            break;
        }
    }
}
