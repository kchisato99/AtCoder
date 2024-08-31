#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, Y;
  cin >> N >> Y;
  int i, j, k;
  for (i = N; i > -1; i--)
  {
    for (j = N - i; j > -1; j--)
    {
      for (k = N - i - j; k > -1; k--)
      {
        if (i + j + k == N && (10000 * i) + (5000 * j) + (1000 * k) == Y)
        {
          cout << i << " " << j << " " << k << endl;
          return 0;
        }
      }
    }
  }
  cout << i << " " << j << " " << k << endl;
  /*
  int i = 0, j = 0, k = 0;
  for (i = 0; i + j + k <= N; i++)
  {
    for (j = 0; i + j + k <= N; j++)
    {
      for (k = 0; i + j + k <= N; k++)
      {
        if ((10000 * i) + (5000 * j) + (1000 * k) == Y &&i + j + k == N)
        {
          cout << i << " " << j << " " << k << endl;
          return 0;
        }
      }
      k = 0;
    }
    j = 0;
  }
   cout << "-1 -1 -1" << endl;
  */
}
