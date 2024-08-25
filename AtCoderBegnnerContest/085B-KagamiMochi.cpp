#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, tmp;
  cin >> N;
  int d[N + 1];
  for (int i = 0; i < N; i++)
  {
    cin >> d[i];
  }

  for (int i = 0; i < N; i++)
  {
    d[N] = 0;
    for (int j = i; j <= N; j++)
    {
      if (j == N)
      {
        d[tmp] = d[i];
        d[i] = d[N];
      }
      else if (d[N] < d[j])
      {
        d[N] = d[j];
        tmp = j;
      }
    }
  }

  int count = 1;
  d[N] = d[0];
  for (int i = 0; i < N; i++)
  {
    if (d[N] > d[i])
    {
      d[N] = d[i];
      count++;
    }
  }
  cout << count << endl;
}