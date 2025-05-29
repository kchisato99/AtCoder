#include <bits/stdc++.h>

using namespace std;

#define min(p, q) ((p) < (q) ? (p) : (q))
#define max(p, q) ((p) > (q) ? (p) : (q))

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
  // 価値の最大はBのいくつかとWのいくつかを選ぶことで得られる

  // 　黒色のボールの価値の最大値を考える
  vector<long long> sumB(N + 1); // 0~N個のボールを選んだ場合の価値の総和
  sumB.at(0) = 0;                // ボールを選ばない場合
  for (int i = 1; i <= N; i++)   // 1個以上のボールを選んだ時
  {
    sumB.at(i) = sumB.at(i - 1) + B.at(i - 1);
  }

  // 白色のボールの価値の最大値を考える
  // 黒色のボールの個数は白色のボール以上になる
  // 価値の総和は黒色のボールi個, 白色のボールj(0<=j<=i)個を選んだ時
  vector<long long> maxW(min(M, N) + 1); // 0~min(N,M)個のボールを選んだ場合の価値の総和
  maxW.at(0) = 0;                        // ボールを選ばない場合
  for (int j = 1; j <= min(M, N); j++)   // 1個以上のボールを選んだ時
  {
    if (W.at(j - 1) > 0)
    {
      maxW.at(j) = maxW.at(j - 1) + W.at(j - 1);
    }
    else
    {
      maxW.at(j) = maxW.at(j - 1);
    }
  }

  // 　黒色と白色のボールをいくつか選んだ時の価値の総和の最大値を求める
  long long sumMax = 0;
  for (int i = 0; i <= N; i++)
  {
    // if (sumMax < sumB.at(i) + maxW.at(min(i, M)))
    sumMax = max(sumMax, sumB.at(i) + maxW.at(min(i, M)));
  }

  cout << sumMax << endl;
}