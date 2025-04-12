#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  int A[N + 1];

  for (int i = 0; i <= N; i++)
  {
    if (i < K)
    {
      A[i] = 1;
    }
    else if (i >= K)
    {
      A[i] = 0;
      for (int j = K; j > 0; --j)
      {
        A[i] += A[i - j];
        if (A[i] >= 1000000000)
        {
          A[i] = A[i] % 1000000000;
        }
      }
    }
    //cout << "A[" << i << "] = " << A[i] << endl;
  }
  cout << A[N] % 1000000000 << endl;
}