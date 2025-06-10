#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  /*
  リュカ数L[i]
  L[0] = 2, L[1] = 1
  L[i] = L[i-1] + L[i-2] (i >= 2)

  N番目のリュカ数を求める
  */

  vector<long long> L(N+1);
  L[0] = 2;
  L[1] = 1;
  for (int i = 2; i <= N; i++)
  {
    L[i] = L[i - 1] + L[i - 2];
  }

  cout << L[N] << endl;
}