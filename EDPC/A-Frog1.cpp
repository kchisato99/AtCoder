#include <bits/stdc++.h>
using namespace std;

#define min(a, b) ((a) < (b) ? (a) : (b))

int main()
{
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++)
  {
    cin >> h[i];
  }

  /*
  n個の足場, 足場iの高さはh[i]
  足場1にカエルがいる,
  カエルは足場iからi+1またはi+2へジャンプする
  ジャンプ先をjとすると, コスト|h[i] - h[j]|を支払う
  足場nにたどり着くまでのコストの総和の最小値を求める
  */

  vector<int> dp(n);
  // dp[i] 足場iにたどり着くまでの最小コスト
  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);
  for (int i = 2; i < n; i++)
  {
    dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                dp[i - 2] + abs(h[i] - h[i - 2]));
  }

  cout << dp[n - 1] << endl;
}