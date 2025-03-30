#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, W;
  cin >> N >> W;
  vector<int> w(N), v(N);
  for (int i = 0; i < N; i++)
  {
    cin >> w[i] >> v[i];
  }

  /*
  N個の品物, 重さw[i], 価値v[i]
  重さの合計W以下になるように選ぶ,
  価値の最大値を求める
  */
  vector<vector<long long>> dp(N + 1, vector<long long>(W + 1));
  // dp[i][j] i-1番目までの品物, 重さjの時の価値の最大値
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j <= W; j++)
    {
      if (j - w[i] >= 0)
      {
        dp[i + 1][j] = max(dp[i][j],
                           dp[i][j - w[i]] + v[i]);
      }
      else
      {
        dp[i + 1][j] = dp[i][j];
      }
      //cout << dp[i + 1][j] << " ";
    }
    //cout << endl;
  }
  cout << dp[N][W] << endl;
}