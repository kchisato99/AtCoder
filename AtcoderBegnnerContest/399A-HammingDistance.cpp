#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;

  string S, T;
  cin >> S >> T;

  /*
  ハミング距離を求める
  */

  int sum = 0;
  for (int i = 0; i < N; i++)
  {
    if (S.at(i) != T.at(i))
    {
      sum++;
    }
  }

  cout << sum << endl;
}