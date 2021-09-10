#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

vector<string> split(string &src) {
    string space_delimiter = " ";
    vector<string> words;

    size_t pos = 0;
    while ((pos = src.find(space_delimiter)) != string::npos) {
        words.push_back(src.substr(0, pos));
        src.erase(0, pos + space_delimiter.length());
    }

    return words;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<string> s(n);
    rep(i, n) {
        getline(cin, s[i]);
    }

    rep(i, n) {
        s[i] += " ";
        vector<string> arr = split(s[i]);
        rep(j, arr.size()) {
            for (int k = arr[j].size() - 1; k >= 0; --k) {
                cout << arr[j][k];
            }
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}