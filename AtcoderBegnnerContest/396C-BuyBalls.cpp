#include <bits/stdc++.h>

using namespace std;

#define min(p, q) ((p) < (q) ? (p) : (q))

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> B(N), W(M);
  for (int i = 0; i < N; i++)
  {
    cin >> B.at(i);
  }
  for (int i = 0; i < M; i++)
  {
    cin >> W.at(i);
  }

  /*
  N個の黒いボールとM個の白いボールがある
  それぞれのボールには価値がつけられている
  黒色のボールの個数が白色のボールの個数以上になるように選ぶとき
  価値の総和としてありうる最大値を求める
  */
  /*
  黒色のボールをi個選んだ時, 白色のボールをj個選んだ時の最大価値
  黒色のボールの数 >= 白色のボールの数
  黒ボールと白ボールを価値の降順にソートして正の数の価値を持つボールを選ぶ
  */
  vector<vector<int>> dp(N + 1, vector<int>(2));
  // 黒ボールと白ボールを価値の降順にソート
  sort(B.rbegin(), B.rend());
  sort(W.rbegin(), W.rend());
  dp[0].at(0) = 0;
  dp[0].at(1) = 300000;
  for (int i = 1; i <= N; i++)
  { // 黒ボールをi個選んだ時
    dp[i].at(0) = dp[i - 1].at(0) + B.at(i - 1);
    // cout << dp[i].at(0) << endl;
    int sum = 0;
    sum = dp[i].at(0);
    if ((dp[i].at(0) + W.at(0) < 0) && dp[i].at(0) < 0)
    { 
      dp[i].at(1) = sum;
      dp[0].at(1) = i;
      break;
    }
    for (int j = 1; j <= min(i, M); j++)
    // 黒色のボールの個数が白色のボールの個数以上になるように選ぶ
    { // 白ボールをj個選んだ時
      if (W.at(j - 1) >= 0)
      {
        sum += W.at(j - 1);
      }
      if (j == i)
      {
        dp[i].at(1) = sum;
      }
    }
  }

  int max = 0;
  for (int i = 1; i <= min(N, dp[0].at(1)); i++)
  {
    if (dp[i].at(1) > max)
    {
      max = dp[i].at(1);
    }
  }
  cout << max << endl;
}