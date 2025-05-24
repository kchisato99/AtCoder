#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  int t[N+1], x[N+1], y[N+1];
  t[0] = x[0] = y[0] = 0;
  for (int i = 0; i < N; i++)
  {
    cin >> t[i+1] >> x[i+1] >> y[i+1];
  }

  bool can = true;
  for (int i = 0; i < N; i++)
  {
    int dt = t[i + 1] - t[i];
    int dist = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
    if (dt < dist)
    {
      can = false;
    }
    if (dist % 2 != dt % 2)
    {
      can = false;
    }
  }

  if(can) {
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }
}