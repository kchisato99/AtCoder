#include <bits/stdc++.h>
using namespace std;

int main()
{
  // 部分文字列の充填率
  string S;
  cin >> S;

  // 部分文字列の生成
  if (S.size() < 3)
  {
    cout << "0.0000000000000000" << endl;
    return 0;
  }
  double ans = 0;
  for (double i = 0; i < S.size(); i++)
  {
    for (double j = i + 3; j <= S.size(); j++)
    {
      if (S[i] == S[j - 1])
      {
        int x = 0;
        for (double k = i; k < j; k++)
        {
          if (S[k] == S[i])
          {
            x++;
          }
        }
        if (ans < ((x - 2) / (j - i - 2)))
        {
          ans = ((x - 2) / (j - i - 2));
        }
      }
    }
  }
  cout << fixed << setprecision(17);
  cout << ans << endl;
}