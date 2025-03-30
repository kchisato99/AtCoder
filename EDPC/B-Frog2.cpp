#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; i++)
  {
    cin >> h[i];
  }

  /*
  足場iにいるとき, 足場i+1, i+2, ..., i+kにジャンプ
  足場nにたどり着くまでの最小コスト
  */

  vector<int> dp(n);
  // dp[i] 足場iにたどり着くまでの最小コスト
  dp[0] = 0;
  for (int i = 1; i < n; i++)
  {
    dp[i] = dp[i-1] + abs(h[i] - h[i - 1]);
    for (int j = 2; j <= k; j++)
    {
      if(i - j < 0)
        break;
      dp[i] = min(dp[i],
                  dp[i - j] + abs(h[i] - h[i - j]));
    }
    // cout << "dp[" << i << "] = " << dp[i] << endl;
  }
  cout << dp[n - 1] << endl;
}