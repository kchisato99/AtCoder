#include <bits/stdc++.h>
using namespace std;
#define max(p, q) ((p) > (q) ? (p) : (q))
int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }

  /*
  長さ N の整数列 A[i]
  Aを一か所で区切って2個の空でない部分列に分割する
  数列に含まれる種類数の和の最大値
  0 < i < N -1
  A[<i], A[i<=]の整数の種類数の最大値 重複を許さずに数える
  */
  vector<vector<int>> dp(N, vector<int>(2));
  // i番目で分割した時の種類数の総和 前半dp[i][0], 後半dp[i][1] でかいほう　dp[i][2]
  set<int> Bi, Afi;
  for (int i = 1; i < N; i++)
  { // i番目で分割
    Bi.insert(A.at(i - 1));
    dp[i-1][0] = Bi.size();
    Afi.clear();
    for (int j = i; j < N; j++)
    {
      Afi.insert(A.at(j));
    }
    dp[i-1][1] = Afi.size();
    //dp[i][2] = max(dp[i][0], dp[i][1]);
    //cout << "test :" << Bi.size() << " " << Afi.size() << endl;
  }

  int ans = 0;
  for (int i = 0; i < N - 1; i++)
  {
    ans = max(ans, dp[i][1] + dp[i][0]);
  }
  cout << ans << endl;
}