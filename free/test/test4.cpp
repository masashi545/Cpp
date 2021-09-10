#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
int const INF = 1e9 + 7;

vector<int> split(string src) {
    string space_delimiter = " ";
    vector<int> words;

    size_t pos = 0;
    while ((pos = src.find(space_delimiter)) != string::npos) {
        words.push_back(atoi(src.substr(0, pos).c_str()));
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
        vector<int> data = split(s[i]);
        rep(j, data.size()) cout << data[i] << " ";
        cout << endl;
    }
    return 0;
}