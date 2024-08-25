#include <bits/stdc++.h>
using namespace std;

int main()
{
  /*
  N個のボールi番目の位置(xi, i)
  タイプA,Bのロボット合計N台
  A i台目を(0, i)
  (0,a)で起動されるとボールの位置まで移動, ボールを回収して(0,a)に戻って停止
  B i台目を(K, i)
  (K,b)で起動されるとボールの位置まで移動, ボールを回収して(0,b)に戻って停止
  2N台のロボットのうちいくつかを起動してボールをすべて回収するとき移動距離の総和の最小値
  */
  int N, K;
  cin >> N >> K;

  int x[N];
  int sum = 0;
  for (int i = 0; i < N; i++)
  {
    cin >> x[i];
    if (x[i] < K)
    {
      if (K - x[i] < x[i])
      {
        sum = sum + (2 * (K - x[i])); // B
      }
      else
      {
        sum = sum + (2 * x[i]); // A
      }
    }
    else
    {
      if (x[i] - K < x[i])
      {
        sum = sum + (2 * (x[i] - K)); // B
      }
      else
      {
        sum = sum + (2 * x[i]); // A
      }
    }
  }
  cout << sum << endl;
}