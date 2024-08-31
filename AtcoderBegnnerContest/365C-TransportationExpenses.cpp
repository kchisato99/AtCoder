#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;

  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }

  if (M <= reduce(A.begin(), A.end()))
  {
    for (int x = *max_element(A.begin(), A.end()); x > 0; x--)
    {
      int sum = 0;
      for (int i = 0; i < N; i++)
      {
        sum += min(x, A.at(i));
      }

      if (sum <= M)
      {
        cout << x << endl;
        return 0;
      }
    }
  }
  else
  {
    cout << "infinite" << endl;
  }
}