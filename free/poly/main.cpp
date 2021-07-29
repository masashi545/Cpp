#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int n1, n2;

deque<int> plus_poly(deque<int> &p1, deque<int> &p2) {
    deque<int> ans;
    while (!p1.empty() || !p2.empty()) {
        int sum = 0;
        if (!p1.empty()) {
            sum += p1.front();
            p1.pop_front();
        }
        if (!p2.empty()) {
            sum += p2.front();
            p2.pop_front();
        }
        ans.push_back(sum);
    }
    return ans;
}

deque<int> mult_poly_int(deque<int> p, int x) {
    deque<int> ans;
    while (!p.empty()) {
        ans.push_back(p.front() * x);
        p.pop_front();
    }
    return ans;
}

void shift_poly(deque<int> &p, int s) {
    while (s) {
        p.push_front(0);
        s--;
    }
}

deque<int> mult_poly(deque<int> p1, deque<int> p2) {
    deque<int> ans;
    int s = 0;
    while (!p2.empty()) {
        deque<int> p = mult_poly_int(p1, p2.front());
        shift_poly(p, s);
        ans = plus_poly(ans, p);
        p2.pop_front();
        s++;
    }
    return ans;
}

void deque_to_string(deque<int> &q) {
    cout << endl;
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop_front();
    }
    cout << endl;
}

int main() {
    cin >> n1;
    n1++;
    deque<int> p1;
    rep(i, n1) {
        int x;
        cin >> x;
        p1.push_back(x);
    }
    cin >> n2;
    n2++;
    deque<int> p2;
    rep(i, n2) {
        int x;
        cin >> x;
        p2.push_back(x);
    }

    // deque<int> ansb = plus_poly(p1, p2);
    deque<int> ansc = mult_poly(p1, p2);

    // deque_to_string(ansb);
    deque_to_string(ansc);
    return 0;
}