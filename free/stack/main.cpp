#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

// スタックのデータ構造
struct Stack {
    stack<int> stk;

    void skip() {
    }

    void push(int n) {
        stk.push(n);
    }

    void pop() {
        if (stk.empty()) {
            cout << "Error!" << endl;
            exit(0);
        }
        stk.pop();
    }

    void plus() {
        if (stk.size() < 2) {
            cout << "Error!" << endl;
            exit(0);
        }
        int s0 = stk.top();
        stk.pop();
        int s1 = stk.top();
        stk.pop();

        stk.push(s1 + s0);
    }

    void minus() {
        if (stk.size() < 2) {
            cout << "Error!" << endl;
            exit(0);
        }
        int s0 = stk.top();
        stk.pop();
        int s1 = stk.top();
        stk.pop();

        stk.push(s1 - s0);
    }

    void le() {
        if (stk.size() < 2) {
            cout << "Error!" << endl;
            exit(0);
        }
        int s0 = stk.top();
        stk.pop();
        int s1 = stk.top();
        stk.pop();

        stk.push(int(s1 <= s0));
    }

    void dup() {
        if (stk.empty()) {
            cout << "Error!" << endl;
            exit(0);
        }
        stk.push(stk.top());
    }

    void whilenz(vector<function<void()>> is) {
        while (true) {
            if (stk.empty()) {
                cout << "Error!" << endl;
                exit(0);
            }
            if (stk.top() == 0) {
                break;
            }
            for (auto f : is) {
                f();
            }
        }
    }

    void whilegt1(vector<function<void()>> is) {
        while (true) {
            if (stk.size() <= 1) {
                break;
            }
            for (auto f : is) {
                f();
            }
        }
    }
};

int main() {
    return 0;
}