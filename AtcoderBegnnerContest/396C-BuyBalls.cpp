#include <bits/stdc++.h>

using namespace std;

#define min(p, q) ((p) < (q) ? (p) : (q))

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> B(N), W(M);
  for (int i = 0; i < N; i++)
  {
    cin >> B.at(i);
  }
  for (int i = 0; i < M; i++)
  {
    cin >> W.at(i);
  }

  /*
  N個の黒いボールとM個の白いボールがある
  それぞれのボールには価値がつけられている
  黒色のボールの個数が白色のボールの個数以上になるように選ぶとき
  価値の総和としてありうる最大値を求める
  */
  // 黒ボールと白ボールを価値の降順にソート
  sort(B.begin(), B.end(), greater<>());
  sort(W.begin(), W.end(), greater<>());
  // 白色のボールをi個選んだ時の最大価値をあらかじめ計算しておく
  vector<int> maxW(M + 1); // maxW[i]: 白色のボールをi個選んだ時の最大価値
  maxW.at(0) = 0;
  for (int i = 1; i <= M; i++)
  {
    if (W.at(i - 1) > 0)
    {
      maxW.at(i) = maxW.at(i - 1) + W.at(i - 1);
    }
    else
    {
      M = i - 1;
      break;
    }
  }
  /*
  MaxW[i]:白色のボールをi個選んだときの最大値
  M:白色のボールの価値が最大の時の個数, iの最大値
  */
  // 黒色のボールをi個, 白色のボールをj個選んだ時の最大価値
  vector<vector<int>> dp(N + 1, vector<int>(2));
  dp[0].at(0) = 0; // 黒色のボールを0個選んだ時の最大価値
  dp[0].at(1) = 0; // 白色のボールを0個選んだ時の最大価値
  for (int i = 1; i <= N; i++)
  { // 黒色のボールをi個選ぶ
    // 黒色のボールをi個, 白色のボールを0個選んだ時の最大価値
    dp[i].at(0) = dp[i - 1].at(0) + B.at(i - 1);
    // 黒色のボールをi個, 白色のボールをj個選んだ時の最大価値
    dp[i].at(1) = dp[i].at(0) + maxW.at(min(i, M));
  }

  for (int i = 0; i <= N; i++)
  {
    if (dp[0].at(1) < dp[i].at(1))
    {
      dp[0].at(1) = dp[i].at(1);
    }
  }
  cout << dp[0].at(1) << endl;
}