#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> h(N);
  for (int i = 0; i < N; i++)
  {
    cin >> h.at(i);
  }

  vector<int> dp(N); // dp[i] = 足場iにたどり着くまでの最小コスト
  dp.at(0) = 0;
  int tmp;
  for (int i = 1; i < N; i++)
  { // iまでの最小値を求める
    dp.at(i) = dp.at(i - 1) + abs(h.at(i - 1) - h.at(i));
    for (int j = 2; j <= K; j++)
    {
      // i-jからiまでの値をそれぞれ比較する
      // i-2, 3 ,K からの最小値を考える
      if (i - j >= 0)
      {
        tmp = dp.at(i - j) + abs(h.at(i - j) - h.at(i));
        if (tmp < dp.at(i))
        {
          dp.at(i) = tmp;
        }
      }else {
        break;
      }
    }
  }

  cout << dp.at(N - 1) << endl;
}