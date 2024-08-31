#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, T, P;
  cin >> N >> T >> P;
  vector<int> L(N);
  for (int i = 0; i < N; i++)
  {
    cin >> L.at(i);
  }

  int day = 0;
  int num = 0;
  while (1)
  {
    num = 0;
    for (int i = 0; i < N; i++)
    {
      if (L.at(i) + day >= T)
      {
        num++;
      }
    }

    if (num < P)
    {
      day++;
    }
    else
    {
      cout << day << endl;
      return 0;
    }
  }
}