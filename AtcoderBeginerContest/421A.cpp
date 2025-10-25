#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++)
  {
    cin >> S[i];
  }
  int X;
  string Y;
  cin >> X >> Y;

  if (Y == S[X - 1])
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}