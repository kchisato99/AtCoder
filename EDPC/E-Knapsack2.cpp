#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, W;
  cin >> N >> W;
  int MAX_V = N * 1000;
  vector<int> w(N), v(N);
  for (int i = 0; i < N; i++)
  {
    cin >> w[i] >> v[i];
  }

  // dp[i][j] i-1番目までの品物, 価値jの時の重さの最小値
  vector<vector<long long>> dp(N + 1, vector<long long>(MAX_V+1, INT_MAX));
  dp[0][0] = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j <= MAX_V; j++)
    {
      if (j - v[i] >= 0)
      {
        dp[i + 1][j] = min(dp[i][j],
                           dp[i][j - v[i]] + w[i]);
      }
      else
      {
        dp[i + 1][j] = dp[i][j];
      }
    }
  }

  int ans = 0;
  for(int i = 0; i <= MAX_V; i++) {
    if(dp[N][i] <= W) {
      ans = i;
      //cout << i << " ";
    }
  }
  cout << ans << endl;

}