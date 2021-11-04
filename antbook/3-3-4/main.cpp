#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9 + 7;

const int B = 1000; // バケットの大きさ

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> L(m), R(m), K(m);
    rep(i, m) cin >> L[i] >> R[i] >> K[i];

    vector<vector<int>> bucket(n / B + 1);
    vector<int> nums(n);

    rep(i, n) {
        bucket[i / B].push_back(a[i]); // バケットに入れていく
        nums[i] = a[i];
    }

    sort(nums.begin(), nums.end());
    // 各バケット内でソート
    rep(i, n / B) {
        sort(bucket[i].begin(), bucket[i].end());
    }

    rep(i, m) {
        // [l,r)のk番目の要素を求める
        int l = L[i];
        int r = R[i] + 1;
        int k = K[i];

        int lb = -1;
        int ub = n - 1;
        while (ub - lb > 1) {
            int mb = (lb + ub) / 2;
            int x = nums[mb];

            int tl = l;
            int tr = r;

            // バケットをはみ出す部分でx以下であるものの個数を数える
            int c = 0;
            while (tl < tr && tl % B != 0) {
                if (a[tl++] <= x)
                    c++;
            }
            while (tl < tr && tr % B != 0) {
                if (a[--tr] <= x)
                    c++;
            }

            // 各バケットでx以下であるものの個数を数える
            // 　この時点で、tlは先頭のバケットの先頭、trは最後のバケットの次の要素
            while (tl < tr) {
                int b = tl / B;
                c += upper_bound(bucket[b].begin(), bucket[b].end(), x) - bucket[b].begin(); //
                tl += B;
            }

            if (c >= k)
                ub = mb;
            else
                lb = mb;
        }
        cout << nums[ub] << endl;
    }
    return 0;
}

/*
in:
7 3
1 5 2 6 3 7 4
1 4 3
3 3 1
0 6 3

out:
5
6
3
*/