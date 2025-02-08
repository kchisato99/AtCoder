#include <bits/stdc++.h>

using namespace std;

int main()
{
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
  // i個目の品物までのうち価値の総和の最高値 dp[i]
  vector<int> dp(N);
  long int sum_max = 0;
  // for (int i = 0; i < N; i++)
  //{
  //  総当たりの裏技
  for (int bit = 0; bit < (1 << N); bit++)
  { // i番目まででいくつか選ぶ時の組み合わせ
    long int sum_w = 0, sum_v = 0;
    for (int j = 0; j < N; j++)
    {
      if (bit & (1 << j))
      {
        sum_w += w.at(j);
        sum_v += v.at(j);
      }
      if (sum_w <= W && sum_v >= sum_max)
      // if (sum_w <= W && sum_v >= dp.at(j))
      {
        sum_max = sum_v;
        // dp.at(i) = sum_v;
      }
    }
  }
  cout << sum_max << endl;
  //}
}