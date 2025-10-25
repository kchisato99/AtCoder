#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  string S;
  cin >> S;
  // 長さ2N N個のA と N個のB からなる
  int ans = 0;
  if(N < 2) {
    cout << 0 << endl;
    return 0;
  }
  if (N >= 2)
  {
    if (S.at(0) != S.at(1) && S.at(1) == S.at(2))
    {
      swap(S.at(0), S.at(1));
      ans++;
    }
  }
  for (int i = 1; i < (2 * N); i++)
  {
    if (S.at(i) == S.at(i - 1)) // 連続しているとき
    {
      // while (S.at(i) == S.at(i - 1))
      for (int j = i + 1; j < 2 * N; j++)
      {
        if (S.at(j) != S.at(j - 1))
        {
          while (j > i)
          {
            swap(S.at(j), S.at(j - 1));
            ans++;
            j--;
          }
          break;
        }
      }
    }
  }

  // cout << S << endl;
  cout << ans << endl;
}