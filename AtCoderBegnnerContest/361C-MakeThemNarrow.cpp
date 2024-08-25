#include <bits/stdc++.h>

using namespace std;

int main()
{
  // 入力
  int K, N;
  cin >> N >> K;

  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  // 要素のソート
  /* int tmp;
  for (int i = 0; i < N; i++)
  {
    for (int j = N - 1; j > i; j--)
    {
      if (A[j - 1] > A[j])
      {
        tmp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = tmp;
      }
    }
  }
*/
  sort(A.begin(), A.end());
  int max, min;
  int sum = A[N - 1] - A[K];
  for (int i = 0; i < K; i++)
  {
    min = A[i];
    max = A[N - 1 + i - K];
    if (sum > max - min)
    {
      sum = max - min;
    }
  }

  cout << sum << endl;
  return 0;
}