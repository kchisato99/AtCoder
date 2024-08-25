#include <bits/stdc++.h>
using namespace std;

int main()
{
  /*
  N個の整数
  すべて偶数のとき, すべてを2で割ったものに置き換える
  最大で何回の操作が行えるか
  */
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  int count = 0;
  bool even;
  while (1)
  {
    for (int i = 0; i < N; i++)
    {
      if (A[i] % 2 != 0)
      {
        even = false;
        break;
      }
      else
      {
        even = true;
      }
    }
    if (even == true)
    {
      for (int i = 0; i < N; i++)
      {
        A[i] = A[i] / 2;
        //cout << A[i] << " ";
      }
      //cout << endl;
      count++;
      continue;
    }
    break;
  }
  cout << count << endl;
}