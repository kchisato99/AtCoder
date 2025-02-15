#include <bits/stdc++.h>

using namespace std;

#define MAX_W 1000000000

#define min(p, q) ((p) < (q) ? (p) : (q))

int main()
{
  // 宣言, 入力
  int N, W;
  cin >> N >> W;
  int MAX_V = N * 1000 + 1;
  vector<long long> w(N);
  vector<int> v(N);
  for (int i = 0; i < N; i++)
  {
    cin >> w.at(i) >> v.at(i);
  }

  /*
  品物iの重さw[i], 価値v[i]
  N個の品物のうちいくつか選び持ち帰る, ナップサックの容量はW, 重さの総和はW以下
  価値の総和の最大値を求める
  */
  // dp[i][val] i-1番目までの品物を価値valとなるように選んだ時の重さの最小値
  // 重さの総和の最小値
  vector<vector<long long>> dp(N + 1, vector<long long>(MAX_V));
  // 初期化
  for (int i = 0; i < N; i++)
  {
    for (int val = 0; val < MAX_V; val++)
    {
      dp[i].at(val) = MAX_W + 1;
    }
  }
  dp[0].at(0) = 0; // 初期条件

  for (int i = 0; i < N; i++)
  { // i 番目までの品物で考える
    for (int val = 0; val < MAX_V; val++)
    {
      if (val - v.at(i) >= 0)
      { // i 番目の品物を選ぶ
        dp[i + 1].at(val) = min(dp[i].at(val),
                                dp[i].at(val - v.at(i)) + w.at(i));
      }
      else
      { // i 番目の品物を選ばない
        dp[i + 1].at(val) = dp[i].at(val);
      }
    }
  }

  // dp[N][val]の値がW以下であるようなjの最大値を求める
  int ans = 0;
  for (int val = 0; val < MAX_V; val++)
  {
    if (dp[N].at(val) <= W)
    {
      ans = val;
      // cout << "value:" << val << " weight:" << dp[N].at(val) << endl;
    }
  }
  cout << ans << endl;
}