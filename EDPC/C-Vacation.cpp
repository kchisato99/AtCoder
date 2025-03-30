#include <bits/stdc++.h>
using namespace std;

//#define max(p, q) ((p) > (q) ? (p) : (q))

int main()
{
  int N;
  cin >> N;
  vector<int> a(N), b(N), c(N);
  for (int i = 0; i < N; i++)
  {
    cin >> a[i] >> b[i] >> c[i];
  }

  /*
  夏休みN日間, i日目の行動
  1. 海で泳ぐ a[i]
  2. 山で虫取り b[i]
  3. 家で宿題 c[i]
  2日連続で同じ活動はできない
  総和の最大値を求める
  */

  // dp[i][j] i日目に行動jを選んだ時
  vector<vector<int>> dp(N, vector<int>(3));
  for (int i = 0; i < N; i++)
  {
    if (i == 0)
    {
      dp[i][0] = a[i];
      dp[i][1] = b[i];
      dp[i][2] = c[i];
    }
    else
    {
      dp[i][0] = a[i] + max(dp[i - 1][1], dp[i - 1][2]);
      dp[i][1] = b[i] + max(dp[i - 1][0], dp[i - 1][2]);
      dp[i][2] = c[i] + max(dp[i - 1][0], dp[i - 1][1]);
    }
  }
  cout << max(dp[N - 1][0],
              max(dp[N - 1][1], dp[N - 1][2]))
       << endl;
}