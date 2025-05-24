#include <bits/stdc++.h>
using namespace std;

int main()
{
  /*
  初期値1
  A 数字を2倍
  B Kを足す
  AとBを合計でN回, 最小の値を求める
  */
  int num = 1;
  int N, K;
  cin >> N >> K;

  for (int i = 0; i < N; i++)
  {
    if (num * 2 < num + K)
    {
      num = num * 2;
    }
    else
    {
      num = num + K;
    }
  }
  cout << num << endl;
}