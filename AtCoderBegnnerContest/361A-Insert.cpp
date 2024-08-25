#include <bits/stdc++.h>

using namespace std;

int main()
{
  // 入力
  int N, K, X;
  cin >> N >> K >> X;
  int A[N];
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  // 処理
  int B[N + 1];
  for (int i = 0; i < K; i++)
  {
    B[i] = A[i];
  }
  B[K] = X;
  for (int i = K + 1; i < N + 1; i++)
  {
    B[i] = A[i - 1];
  }

  // 出力
  for (int i = 0; i < N + 1; i++)
  {
    cout << B[i] << " ";
  }
  cout << endl;
}