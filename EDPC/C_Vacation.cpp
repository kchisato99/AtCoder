#include <bits/stdc++.h>

using namespace std;

#define max(p, q) ((p) > (q) ? (p) : (q))

int main()
{
  int N;
  cin >> N;
  vector<int> a(N), b(N), c(N);
  for (int i = 0; i < N; i++)
  {
    cin >> a.at(i) >> b.at(i) >> c.at(i);
  }

  /*
  夏休みの計画を立てる
  夏休みはN日間, i日目に幸福度A[i], B[i], C[i]の活動ができる
  2日連続して同じ活動はできない
  */
  // i日目に活動jを選んだ時の最大幸福度dp[i][j]
  vector<vector<int>> dp(N, vector<int>(3));
  dp.at(0).at(0) = a.at(0); // 海で泳ぐ a[i]
  dp.at(0).at(1) = b.at(0); // 山で虫取り b[i]
  dp.at(0).at(2) = c.at(0); // 家で宿題 c[i]

  for (int i = 1; i < N; i++)
  {
    // i日目に行動aをする場合, i-1日目の行動はb, c のどちらか
    dp.at(i).at(0) = max(dp.at(i - 1).at(1) + a.at(i),
                         dp.at(i - 1).at(2) + a.at(i));
    dp.at(i).at(1) = max(dp.at(i - 1).at(0) + b.at(i),
                         dp.at(i - 1).at(2) + b.at(i));
    dp.at(i).at(2) = max(dp.at(i - 1).at(0) + c.at(i),
                         dp.at(i - 1).at(1) + c.at(i));
  }

  // N日目の最大幸福度
  int max_happiness = max(max(dp.at(N - 1).at(0), dp.at(N - 1).at(1)),
                          dp.at(N - 1).at(2));

  cout << max_happiness << endl;
}