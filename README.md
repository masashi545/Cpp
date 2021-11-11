# 蟻本

## [AtCoder 版！蟻本 (初級編)](https://qiita.com/drken/items/e77685614f3c6bf86f44)
+ [例題1-6-1](antbook/1-6-1/main.cpp) 三角形 
    - [ARC004-A](https://atcoder.jp/contests/arc004/tasks/arc004_1) 2点間距離の最大値 [code](arc004/a/main.cpp)
    - [ABC051-B](https://atcoder.jp/contests/abc051/tasks/abc051_b) Sum of Three Integers [code](abc051/b/main.cpp)
    - [ABC085-C](https://atcoder.jp/contests/abc085/tasks/abc085_c) Otoshidama [code](abc085/c/main.cpp)
    - [ABC175-B](https://atcoder.jp/contests/abc175/tasks/abc175_b) Making Triangle [code](abc175/b/main.cpp)
+ [例題1-6-2](antbook/1-6-2/main.cpp) Ants
    - [AGC013-C](https://atcoder.jp/contests/agc013/tasks/agc013_c) Ants on a Circle [code](agc013/c/main.cpp)

### 全探索
+ [例題 2-1-1](antbook/2-1-1/main.cpp) 部分和問題
    - [ARC061-C](https://atcoder.jp/contests/arc061/tasks/arc061_a) たくさんの数式 [code](arc061/c/main.cpp)
    - [ABC079-C](https://atcoder.jp/contests/abc079/tasks/abc079_c) Train Ticket [code](abc079/c/main.cpp)
    - [ABC104-C](https://atcoder.jp/contests/abc104/tasks/abc104_c) All Green [code](abc104/c/main.cpp)
    - [ARC029-A](https://atcoder.jp/contests/arc029/tasks/arc029_1) 高橋君とお肉 [code](arc029/a/main.cpp)
    - [ABC002-D](https://atcoder.jp/contests/abc002/tasks/abc002_4) 派閥 [code](abc002/d/main.cpp)
+ [例題 2-1-2](antbook/2-1-2/main.cpp) Lake Counting(深さ優先探索DFS->2^nになる恐れあり) -> stack
    - [ATC001-A](https://atcoder.jp/contests/atc001/tasks/dfs_a) 深さ優先探索 [code](atc001/a/main.cpp)
    - [ARC031-B](https://atcoder.jp/contests/arc031/tasks/arc031_2) 埋め立て [code](arc031/b/main.cpp)
    - [ARC037-B](https://atcoder.jp/contests/arc037/tasks/arc037_b) バウムテスト [code](arc037/b/main.cpp)
+ [例題 2-1-3](antbook/2-1-3/main.cpp) 迷路の最短路(幅優先探索BFS->状態数x遷移の仕方) -> queue
    - [ABC007-C](https://atcoder.jp/contests/abc007/tasks/abc007_3) 幅優先探索 [code](abc007/c/main.cpp)
+ [例題 2-1-4](antbook/2-1-4/main.cpp) 特殊な状態の列挙
    - [ABC054-C](https://atcoder.jp/contests/abc054/tasks/abc054_c) One-stroke Path [code](abc054/c/main.cpp)

### 貪欲法
+ [例題2-2-1](antbook/2-2-1/main.cpp) 硬貨の問題
    - [JOI2008予選-A](https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_a) おつり [code](joi2008yo/a/main.cpp)
    - [AOJDPL-1_A](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_A&lang=jp) コイン問題(個数制限なしナップサックDP) [code](aojdpl/1-a/main.cpp)
+ [例題2-2-2](antbook/2-2-2/main.cpp) 区間スケジューリング問題
    - [Keyence2020-B](https://atcoder.jp/contests/keyence2020/tasks/keyence2020_b) Robot Arms [code](keyence2020/b/main.cpp)
+ [例題2-2-3](antbook/2-2-3/main.cpp) Best Cow Line（辞書順最小）
    - [ABC076-C](https://atcoder.jp/contests/abc076/tasks/abc076_c) Dubious Document 2 [code](abc076/c/main.cpp)
+ [例題2-2-4](antbook/2-2-4/main.cpp) Saruman's Army
    - [ABC083-C](https://atcoder.jp/contests/abc083/tasks/arc088_a) Multiple Gift [code](abc083/c/main.cpp)
+ [例題2-2-5](antbook/2-2-5/main.cpp) Fence Repair
    - [Codeforces462-C](http://codeforces.com/contest/462/problem/C) Appleman and Toastman [code](codeforces462/c/main.cpp)

### 動的計画法1
+ [例題2-3-1(メモ化、再帰関数)](antbook/2-3-1/main1.cpp) 01ナップサック問題 [全探索](antbook/2-3-1/main0.cpp) [漸化式、ループ](antbook/2-3-1/main2.cpp)
    - [AOJDPL-1_B](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B&lang=jp) 01ナップサック問題 [code](aojdpl/1-b/main.cpp)
    - [TDPC-A](https://atcoder.jp/contests/tdpc/tasks/tdpc_contest) コンテスト (部分和問題) [code](tdpc/a/main.cpp)
+ [例題2-3-2](antbook/2-3-2/main.cpp) 最長共通部分列問題(LCS)
    - [AOJALDS1-10_C](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=jp) 最長共通部分列問題 [code](aojalds1/10-c/main.cpp)
    - [AOJDPL-1_E](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E&lang=jp) 編集距離 [code](aojdpl/1-e/main.cpp)
+ [例題2-3-3](antbook/2-3-3/main.cpp) 個数制限なしナップサック問題
    - [AOJDPL-1_C](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C&lang=jp) ナップサック問題 [code](aojdpl/1-c/main.cpp)
    - [ABC153-E](https://atcoder.jp/contests/abc153/tasks/abc153_e) Crested Ibis vs Monster [code](abc153/e/main.cpp)
+ [例題2-3-4](antbook/2-3-4/main.cpp) 01ナップサック問題その2
    - [ABC032-D](https://atcoder.jp/contests/abc032/tasks/abc032_d) ナップサック問題(半分全列挙) [code](abc032/d/main.cpp)
    - [ARC057-B](https://atcoder.jp/contests/arc057/tasks/arc057_b) 高橋君ゲーム(WA:20) [code](arc057/b/main.cpp)
+ [例題2-3-5](antbook/2-3-5/main.cpp) 個数制限付き部分和問題
    - [MaximumCup2018-D](https://atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_d) Many Go Round [code](maximum-cup-2018/d/main.cpp)
+ [例題2-3-6](antbook/2-3-6/main.cpp) 最長増加部分列問題(LIS)
    - [ChokudaiSpeedRun001-H](https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_h) LIS [code](chokudai_S001/h/main.cpp)
    - [ABC006-D](https://atcoder.jp/contests/abc006/tasks/abc006_4) トランプ挿入ソート [code](abc006/d/main.cpp)
    - [ABC038-D](https://atcoder.jp/contests/abc038/tasks/abc038_d) プレゼント(わからない)<-2分探索 [code](abc038/d/main.cpp)
+ [例題2-3-7](antbook/2-3-7/main.cpp) 分割数
    - [yukicoder-269](https://yukicoder.me/problems/no/269) 見栄っ張りの募金活動 [code](yukicoder/269/main.cpp)
+ [例題2-3-8](antbook/2-3-8/main.cpp) 重複組合せ
    - [ABC110-D](https://atcoder.jp/contests/abc110/tasks/abc110_d) Factorization(素因数分解) [code](abc110/d/main.cpp)

### データ構造
+ [例題2-4-1](antbook/2-4-1/main.cpp) Expedition(priority_queue, heap)
    - [CodeThanksFestival-C](https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_c) Factory [code](code-thanks-festival-2017/c/main.cpp)
+ [例題2-4-2](antbook/2-4-2/main.cpp) 二分探索木(set,map)
    - [ABC085-B](https://atcoder.jp/contests/abc085/tasks/abc085_b) Kagami Mochi(set) [code](abc085/b/main.cpp)
    - [ABC091-B](https://atcoder.jp/contests/abc091/tasks/abc091_b) Two Colors Card Game(map) [code](abc091/b/main.cpp)
+ [例題2-4-3](antbook/2-4-3/main.cpp) 食物連鎖(Union-Find木)
    - [ATC001-B](https://atcoder.jp/contests/atc001/tasks/unionfind_a) Union Find [code](atc001/b/main.cpp)
    - [ABC049-D](https://atcoder.jp/contests/abc049/tasks/arc065_b) 連結(Union-Find -> map) [code](abc049/d/main.cpp)

### グラフ
+ [例題2-5-1](antbook/2-5-1/main.cpp) 二部グラフ判定
    - [ABC126-D](https://atcoder.jp/contests/abc126/tasks/abc126_d) Even Relation [code](abc126/d/main.cpp)
+ [例題2-5-2](antbook/2-5-2/main.cpp) Roadblocks(Dijkstra、2番目に最短な経路)
    - [SoundHound2018SummerQual-D](https://atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_d) Saving Snuuk [code](soundhound2018-summer-qual/d/main.cpp)
+ [例題2-5-3](antbook/2-5-3/main.cpp) Conscription(Kruskal)
    - [AOJGRL-2_A](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp) Minimum Spanning Tree [code](aojgrl/2-a/main.cpp)
    - [ABC065-D](https://atcoder.jp/contests/abc065/tasks/arc076_b) Built?(Kruskal, 枝刈り) [code](abc065/d/main.cpp)
+ [例題2-5-4](antbook/2-5-4/main.cpp) Layout(最短経路問題への帰着)
    - [AOJGRL-1_B](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=jp) Single Source Shortest Path (Negative Edges) [code](aojgrl/1-b/main.cpp)
    - [ABC061-D](https://atcoder.jp/contests/abc061/tasks/abc061_d) Score Attack [code](abc061/d/main.cpp)
+ [例題2-5-5] Warshall-Floyd法を使った問題
    - [ABC012-D](https://atcoder.jp/contests/abc012/tasks/abc012_4) バスと避けられない運命 [code](abc012/d/main.cpp)
    - [ABC073-D](https://atcoder.jp/contests/abc073/tasks/abc073_d) joisino's travel [code](abc073/d/main.cpp)

### 数学的な問題
+ [例題2-6-1](antbook/2-6-1/main.cpp) 線分上の格子点の個数(ユーグリッドの互除法)
    - [AOJVol-0583](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0583) Common Divisors [code](aojvol/0583/main.cpp)
    - [ABC070-C](https://atcoder.jp/contests/abc070/tasks/abc070_c) Multiple Clocks [code](abc070/c/main.cpp)
    - [AGC001-B](https://atcoder.jp/contests/agc001/tasks/agc001_b) Mysterious Light [code](agc001/b/main.cpp)
+ [例題2-6-2](antbook/2-6-2/main.cpp) 双六(拡張ユーグリッドの互除法)
    - [AOJNTL-1_E](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=ja) [code](aojntl/1-e/main.cpp)
+ [例題2-6-3](antbook/2-6-3/main.cpp) 素数判定
    - [ARC017-A](https://atcoder.jp/contests/arc017/tasks/arc017_1) 素数、コンテスト、素数 [code](arc017/a/main.cpp)
    - [ABC052-C](https://atcoder.jp/contests/abc052/tasks/arc067_a) Factors of Factorial [code](abc052/c/main.cpp)
    - [ABC110-D](https://atcoder.jp/contests/abc110/tasks/abc110_d) Factorization [code](abc110/d/main.cpp)
+ [例題2-6-4](antbook/2-6-4/main.cpp) 素数の個数
    - [ABC084-D](https://atcoder.jp/contests/abc084/tasks/abc084_d) 2017-like Number [code](abc084/d/main.cpp)
    - [AOJVol-2286](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2286) Farey Sequence(わからん) [code](aojvol/2286/main.cpp)
+ [例題2-6-5](antbook/2-6-5/main.cpp) 区間内の素数の個数
    - [JAG2017秋](https://atcoder.jp/contests/jag2017autumn/tasks/jag2017autumn_c) Prime-Factor Prime(わからん) [code](jag2017autumn/c/main.cpp)
+ [例題2-6-6](antbook/2-6-6/main.cpp) Carmichael Numbers(べき乗の高速化)
    - [JOI2007春合宿-fermat](https://atcoder.jp/contests/joisc2007/tasks/joisc2007_fermat) フェルマー方程式 [code](joisc2007/fermat/main.cpp)


## [AtCoder 版！蟻本 (中級編)](https://qiita.com/drken/items/2f56925972c1d34e05d8)
### 二分探索
+ [例題3-1-1](antbook/3-1-1/main.cpp) lower_bound(ソート列から値を探す)
    - [ABC077-C](https://atcoder.jp/contests/abc077/tasks/arc084_a) Snuke Festival [code](abc077/c/main.cpp)
+ [例題3-1-2](antbook/3-1-2/main.cpp) Cable master(解を仮定し条件を満たすか判定)
    - [ABC023-D](https://atcoder.jp/contests/abc023/tasks/abc023_d) 射撃王 [code](abc023/d/main.cpp)
+ [例題3-1-3](antbook/3-1-3/main.cpp) Aggressive cows(最小値の最大化)
    - [CodeFes2015予選A-D](https://atcoder.jp/contests/code-festival-2015-quala/tasks/codefestival_2015_qualA_d) 壊れた電車 [code](code-festival-2015-quala/d/main.cpp)
+ [例題3-1-4](antbook/3-1-4/main.cpp) 平均最大化
    - [ABC034-D](https://atcoder.jp/contests/abc034/tasks/abc034_d) 食塩水 [code](abc034/d/main.cpp)

### 頻出テクニック(1)
+ [例題3-2-1](antbook/3-2-1/main.cpp) Subsequence(しゃくとり法)
    - [AOJDSL-3_C](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_C&lang=jp) The Number of Windows [code](aojdsl/3-c/main.cpp)
+ [例題3-2-2](antbook/3-2-2/main.cpp) Jessica's Reading Problem(しゃくとり法、map)
    - [ARC022-B](https://atcoder.jp/contests/arc022/tasks/arc022_2) 細長いお菓子 [code](arc022/b/main.cpp)
+ [例題3-2-3](antbook/3-2-3/main.cpp) Face The Right Way(区間反転)
    - [ARC064-C](https://atcoder.jp/contests/arc064/tasks/arc064_a) Boxes and Candies(左から貪欲に) [code](arc064/c/main.cpp)
+ [例題3-2-4](antbook/3-2-4/main.cpp) Fliptile(反転)
    - [JOI2008予選-E](https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_e) おせんべい(横を決めたら縦が決まる) [code](joi2008yo/e/main.cpp)
+ [例題3-2-5](antbook/3-2-5/main.cpp) Physics Experiment(弾性衝突)
    - [AGC013-C](https://atcoder.jp/contests/agc013/tasks/agc013_c) Ants on a Circle [code](agc013/c/main.cpp)
+ [例題3-2-6](antbook/3-2-6/main.cpp) 4 Values whose Sum is 0(半分全列挙)
    - [JOI2008本戦-C](https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c) ダーツ [code](joi2008ho/c/main.cpp)
+ [例題3-2-7](antbook/3-2-7/main.cpp) 巨大ナップサック(重さも価値も大きいが、nが小さいとき->半分全列挙)
    - [AOJDPL-1_H](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H&lang=jp) Huge Knapsack Problem [code](aojdpl/1-h/main.cpp)
+ [例題3-2-8](antbook/3-2-8/main.cpp) 領域の個数(座標圧縮)
    - [JOI2008本戦-E](https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_e) ペンキの色(座圧、BFS、imos法) [code](joi2008ho/e/main.cpp)
    - [ABC213-C](https://atcoder.jp/contests/abc213/tasks/abc213_c) Reorder Cards(まだ) [code](abc213/c/main.cpp)

### さまざまなデータ構造
+ [例題3-3-1](antbook/3-3-1/main.cpp) Crane(セグメント木)
    - [AOJDSL-2_A](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp) Range Minimum Query(RMQ) [code](aojdsl/2-a/main.cpp)
+ [例題3-3-2](antbook/3-3-2/main.cpp) バブルソートの交換回数(BIT)
    - [AOJALDS1-5_D](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D&lang=jp) The Number of Inversions [code](aojalds1/5-d/main.cpp)
+ [例題3-3-3](antbook/3-3-3/main.cpp) A Simple Problem with Integers(区間加算対応RSQ)
    - [AOJDSL-2_G](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=jp) RSQ and RAQ [code](aojdsl/2-g/main.cpp) 
    - [AOJDSL-2_H](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=jp) RMQ and RAQ(まだ) [code](aojdsl/2-h/main.cpp) 
+ [例題3-3-4](antbook/3-3-4/main.cpp) K-th Number(平方分割)
    - [ARC033-C](https://atcoder.jp/contests/arc033/tasks/arc033_3) データ構造(わからん) [code](arc033/c/main.cpp)

### 動的計画法2
+ [例題3-4-1](antbook/3-4-1/main.cpp) 巡回セールスマン問題
    - [ABC180-E](https://atcoder.jp/contests/abc180/tasks/abc180_e) Traveling Salesman among Aerial Cities [code](abc180/e/main.cpp)
+ [例題3-4-2](antbook/3-4-2/main.cpp) Traveling by Stagecoach
    - [みんなのプロコン2018-C](https://atcoder.jp/contests/yahoo-procon2018-qual/tasks/yahoo_procon2018_qual_c) 駆引取引 [code](yahoo-procon2018-qual/c/main.cpp) 
+ [例題3-4-3](antbook/3-4-3/main.cpp) ドミノ敷き詰め
    - [JOI2011予選-F](https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_f) JOI 旗 [code](joi2011yo/f/main.cpp)
+ [例題3-4-4](antbook/3-4-4/main.cpp) フィボナッチ数列(行列累乗)
    - [ABC009-D](https://atcoder.jp/contests/abc009/tasks/abc009_4) 漸化式 [code](abc009/d/main.cpp)
+ [例題3-4-5](antbook/3-4-5/main.cpp) Blocks(m項間漸化式、行列累乗)
    - [TDPC-M](https://atcoder.jp/contests/tdpc/tasks/tdpc_house) 家(わからない) [code](tdpc/m/main.cpp)
+ [例題3-4-6](antbook/3-4-6/main.cpp) グラフの長さkのパスの総数(隣接行列の累乗)
    - [DPまとめ-R](https://atcoder.jp/contests/dp/tasks/dp_r) Walk [code](dp/r/main.cpp)
+ [例題3-4-7](antbook/3-4-7/main.cpp) Matrix Power Series(行列の累乗和)
+ [例題3-4-8](antbook/3-4-8/main.cpp) Minimizing Maximizer
    - [ドワンゴ2018本選-B](https://atcoder.jp/contests/dwacon2018-final-open/tasks/dwacon2018_final_b) だんだん強く [code](dwacon2018-final-open/b/main.cpp)

### ネットワークフロー
+ [例題3-5-1](antbook/3-5-1/main.cpp) 最大通信量(最大流問題)
    - [ABC010-D](https://atcoder.jp/contests/abc010/tasks/abc010_4) 浮気予防 [code](abc010/d/main.cpp)
+ [例題3-5-2](antbook/3-5-2/main.cpp) 仕事も割り当て(二部マッチング)
    - [ABC091-C](https://atcoder.jp/contests/abc091/tasks/arc092_a) 2D Plane 2N Points [code](abc091/c/main.cpp)
    - [AOJVol-1163](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1163&lang=jp) Cards [code](aojvol/1163/main.cpp)


+ [例題](antbook//main.cpp) 
    - []() [code](/main.cpp)


# ライブラリ
### グラフ
+ [Union-Find木](free/graph/Union-Find.cpp)
+ セグメント木
    - [RMQ](free/graph/ST-RMQ.cpp)
    - [区間加算対応RSQ](free/graph/ST-RSQ-kai.cpp)
+ [BIT](free/graph/BIT.cpp)
+ 最短経路問題
    - 単一始点
        + [Bellman-Ford法](free/graph/Bellman-Ford.cpp) -> $O(|V||E|)$ コスト負の辺がある場合有効
        + [Dijkstra法](free/graph/Dijkstra.cpp) -> $O(|E|log|V|)$
    - 全頂点対
        + [Warshall-Floyd法](free/graph/Warshall-Floyd.cpp) -> $O(|V|^3)$
+ 最小全域木問題
    - [Prim法](free/graph/Prim.cpp) -> $O(|E|log|V|)$
    - [Kruskal法](free/graph/Kruskal.cpp) -> $O(|E|log|V|)$
+ 最大流問題
    - [Ford-Fulkerson法](free/graph/Ford-Fulkerson.cpp) -> $O(F|E|)$
    - [Dinic法](free/graph/Dinic.cpp) -> $O(|E||V|)$

### 整数
+ [ユーグリッドの互除法](free/num/gcd.cpp) -> $O(logmax(a,b))$
+ 素数問題
    - [素数判定](free/num/is_prime.cpp) -> $O(\sqrt{n})$
    - [約数列挙](free/num/divisor.cpp) -> $O(\sqrt{n})$
    - [素因数分解](free/num/prime_factor.cpp) -> $O(\sqrt{n})$
    - [素数列挙(エラトステネスの篩)](free/num/eratosthenes.cpp) -> $O(nloglogn)$
+ [べき乗計算(繰り返し2乗法)](free/num/mod_pow.cpp) -> $O(logn)$
