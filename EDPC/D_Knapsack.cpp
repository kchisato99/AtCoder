#include <bits/stdc++.h>

using namespace std;

#define max(p, q) ((p) > (q) ? (p) : (q))

int main()
{
  // 入力, 宣言
  int N, W; // N個の品物, ナップサックの容量W
  cin >> N >> W;
  vector<int> w(N), v(N); // 品物i の重さw[i], 価値v[i]
  for (int i = 0; i < N; i++)
  {
    cin >> w.at(i) >> v.at(i);
  }

  /*
  N個から選んで持ち帰る
  ナップサックの容量はW, 総和はW以下でなければならない
  価値の総和の最大値を求める
  */
  // dp[i][j] i-1個目の品物までで重さがj以下となるように選んだときの価値の総和の最大値
  vector<vector<long long>> dp(N + 1, vector<long long>(W + 1));
  // dp[i][j]が求まっている状態でdp[i+1][j]を更新する
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j <= W; j++)
    {
      if (j - w.at(i) >= 0)
      { // i 番目の品物を選ぶ
        dp[i + 1].at(j) = max(dp[i].at(j),
                              dp[i].at(j - w.at(i)) + v.at(i));
      }
      else
      { // i 番目の品物を選ばない
        dp[i + 1].at(j) = dp[i].at(j);
      }
    }
  }
  /*
  for (int i = 0; i <= N; i++)
  {
    for (int j = 0; j <= W; j++)
    {
      cout << setw(2) << dp[i].at(j) << " ";
    }
    cout << endl;
  }*/
  cout << dp[N].at(W) << endl;
}