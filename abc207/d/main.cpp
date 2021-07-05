#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N), c(N), d(N);
    int mean_a = 0, mean_b = 0, mean_c = 0, mean_d = 0; // 重心

    // Sの点を、入力処理しつつ重心を原点に並行移動する
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        mean_a += x;
        mean_b += y;
        a[i] = x * N; // 少数はいやなので、全ての座標をN倍して考える
        b[i] = y * N; // 全ての座標をN倍してるので、重心を求める時、総和をNで割る必要がなくなる
    }
    for (int i = 0; i < N; i++) {
        a[i] -= mean_a; // 全ての座標から重心を引くことで、重心を(0,0)にする
        b[i] -= mean_b;
    }

    // Tの点を、入力処理しつつ重心を原点に並行移動する
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        mean_c += x;
        mean_d += y;
        c[i] = x * N; // 少数はいやなので、全ての座標をN倍して考える
        d[i] = y * N; // 全ての座標をN倍してるので、重心を求める時、総和をNで割る必要がなくなる
    }
    for (int i = 0; i < N; i++) {
        c[i] -= mean_c; // 全ての座標から重心を引くことで、重心を(0,0)にする
        d[i] -= mean_d;
    }

    // 基準点として、Sの点のうち、重心(0,0)でない点を選ぶ
    for (int i = 0; i < N; i++) {
        if (a[i] != 0 || b[i] != 0) {
            swap(a[i], a[0]);
            swap(b[i], b[0]);
        }
    }

    // 基準点(a[0],b[0])を、(c[i],d[i])に順に対応させる
    string ans = "No";
    const double eps = 1e-6; // 非常に小さい定数(点の一致判定に使う)
    for (int i = 0; i < N; i++) {
        double angle = 0.0;
        if (c[i] != 0 || d[i] != 0) {
            angle = atan2(d[i], c[i]) - atan2(b[0], a[0]); // 対応させる点との偏角を求める
        }

        bool flag1 = true; // 全ての点を対応できているかどうかのフラグ
        // (a[j],b[j])を回転させて、対応する点があるか判定する
        for (int j = 0; j < N; j++) {
            if (!flag1) { // 対応できない点があった時点で、はじめの(a[0],b[0])と(c[i],d[i])の対応は却下
                break;
            }
            double A = a[j] * cos(angle) - b[j] * sin(angle);
            double B = a[j] * sin(angle) + b[j] * cos(angle);

            bool flag2 = false; // (a[j],b[j])を回転させた点と、一致する点があるかどうかのフラグ
            // 対応する点を(c[k],d[k])の中から探す
            for (int k = 0; k < N; k++) {
                if (abs(A - c[k]) <= eps && abs(B - d[k]) <= eps) {
                    flag2 = true; // 一致する点があればフラグを立てる
                    break;
                }
            }
            flag1 &= flag2; // (a[j],b[j])に対応する点があれば、今のところ全ての点を対応できている
        }

        if (flag1) { // 全ての点を対応できた時点で、Yesを出力して終了
            ans = "Yes";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}