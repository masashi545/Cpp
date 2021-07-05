#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    sort(A.begin(), A.end());

    string res = "Yes";
    for (int i = 0; i < N; i++) {
        if (A.at(i) != i + 1) {
            res = "No";
            break;
        }
    }

    cout << res << endl;
}

/*
int main() {
    int N;
    cin >> N;
    vector<bool> appear(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        appear[a - 1] = true; // 
    }
    for (int i = 0; i < N; i++) {
        if (!appear[i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}*/