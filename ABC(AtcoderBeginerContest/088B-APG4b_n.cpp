#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, tmp;
  cin >> N;
  int a[N + 1];
  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
  }

  int Alice = 0, Bob = 0;
  for (int i = 0; i < N; i++)
  {
    a[N] = 0;
    for (int j = i; j <= N; j++)
    {
      if (j == N)
      {
        a[tmp] = a[i];
        a[i] = a[N];
      }
      else if (a[N] < a[j])
      {
        a[N] = a[j];
        tmp = j;
      }
    }

    if (i % 2 == 0)
    {
      Alice += a[i];
    }
    else
    {
      Bob += a[i];
    }
  }
  cout << Alice - Bob << endl;
}