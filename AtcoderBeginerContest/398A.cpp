#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  /*
  長さNの文字列を求める
  - or =
  回文
  =は1個または2個含まれる, それらは隣接している
  */
  string s(N, '=');
  if (N % 2 == 0 && N > 1)
  {
    for (int i = 0; i < (N / 2) - 1; i++)
    {
      s.at(i) = '-';
      s.at(N - 1 - i) = '-';
    }
    s.at((N / 2) - 1) = '=';
    s.at(N / 2) = '=';
  }
  else if (N % 2 != 0 && N > 1)
  {
    for (int i = 0; i < (N / 2); i++)
    {
      s.at(i) = '-';
      s.at(N - 1 - i) = '-';
    }
    s.at(N / 2) = '=';
  }
  /*else if (N == 1)
  {
    s.at(0) = '=';
  }*/

  cout << s << endl;
}