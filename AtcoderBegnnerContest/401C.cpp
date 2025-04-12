#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  long long A[N + 1];
  long long s = K;

  for (int i = 0; i <= N; i++)
  {
    if (i < K)
    {
      A[i] = 1;
    }
    else if (i >= K)
    {
      A[i] = s;
      s -= A[i - K] % 1000000000;
      s += A[i];
      if (s % 10000000000 > 1000000000)
        s %= 10000000000;
    }
    // cout << "A[" << i << "] = " << A[i] << endl;
  }
  cout << A[N] % 1000000000 << endl;
}