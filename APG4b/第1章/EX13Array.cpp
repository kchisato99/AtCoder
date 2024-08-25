#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, avg;
  cin >> N;

  int A[N];
  int sum = 0;
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
    sum = sum + A[i];
  }
  avg = sum / N;

  for (int i = 0; i < N; i++)
  {
    if (A[i] - avg >= 0)
    {
      cout << A[i] - avg << endl;
    }
    else
    {
      cout << avg - A[i] << endl;
    }
  }
}