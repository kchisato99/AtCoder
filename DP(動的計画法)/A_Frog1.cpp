#include <bits/stdc++.h>

using namespace std;

#define min(p, q) ((p) < (q) ? (p) : (q))

int main()
{
  int N;
  cin >> N;
  vector<int> h(N);
  for (int i = 0; i < N; i++)
  {
    cin >> h.at(i);
  }

  vector<int> dp(N);
  dp.at(0) = 0;
  dp.at(1) = dp.at(0) + abs(h.at(1) - h.at(0));
  /*
  足場Nにたどり着くのは, 足場N-1またはN-2からのジャンプ
  dp[i] = 足場iにたどり着くまでの最小コスト を調べる
  */
  for (int i = 2; i < N; i++)
  {
    dp.at(i) = min(dp.at(i - 1) + abs(h.at(i - 1) - h.at(i)),
                   dp.at(i - 2) + abs(h.at(i - 2) - h.at(i)));
    // 足場i-1からジャンプした場合と, 足場i-2からジャンプした場合のコストを比較
  }

  cout << dp.at(N - 1) << endl;
}