#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  // N組の団体, 席lから席rの連続で座る
  cin >> N;
  int Seat[2 * N];
  int sum = 0;
  for (int i = 0; i < N; i++)
  {
    cin >> Seat[2 * i] >> Seat[(2 * i) + 1];
    sum = sum + (Seat[(2*i)+1] - (Seat[2*i]-1));
  }
  cout << sum << endl;
}