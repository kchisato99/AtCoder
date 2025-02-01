#include <bits/stdc++.h>

using namespace std;

int main()
{
  /*
  総合スコアをG点以上にするために必要な最小の問題数を求める
  100i点をつけられた問題がp[i]問
  基本スコア:問題の配点の合計
  完答ボーナス:100i点をつけられたp[i]問を全て解いた場合
    に得られるc[i]点のボーナス
  */
  // 入力
  //  c[i], G はすべて100の倍数
  int D, G; // 1<=D<=10, 100<=G
  cin >> D >> G;
  vector<int> p(D), c(D);
  for (int i = 0; i < D; i++)
  {
    cin >> p[i] >> c[i];
  }

  // 処理
  //  総合スコアをG点以上にするために必要な最小の問題数
  //  100i点をつけられた問題がp[i]問, コンプリートボーナスc[i]点
  /*取りうる最大の得点を求める
  Dが10のときに最大得点
  */
  int MAX = 0;





  
  for (int i = 0; i < D; i++)
  {
    MAX = MAX + 100 * i * p[i] + c[i];
    cout << i << " " << p[i] << endl;
  }

  // dp[i][num] = i問目までの問題をnum問解いたときの最大得点
  vector<vector<int>> dp(D + 1, vector<int>(G + 1, 0));
  for (int i = 0; i < D; i++)
  {
    for (int num = 0; num <= p[i]; num++)
    {
      for (int j = 0; j <= G; j++)
      {
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      }
    }
  }
  // 出力
  cout << MAX << endl;
  return 0;
}