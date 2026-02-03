#include <bits/stdc++.h>

using namespace std;

int main()
{
  // 入力
  string Num;
  cin >> Num;
  char mark[3];

  // 処理
  for (int bit = 0; bit < (1 << 3); bit++)
  {
    bitset<3> op(bit);
    int ans = Num.at(0) - '0';
    for (int i = 0; i < 3; i++)
    {
      if (op.test(i))
      {
        ans += Num.at(i + 1) - '0';
      }
      else
      {
        ans -= Num.at(i + 1) - '0';
      }
    }
    //cout << "test : " << ans << endl;

    if (ans == 7)
    {
      for (int i = 0; i < 3; i++)
      {
        if (op.test(i))
        {
          mark[i] = '+';
        }
        else
        {
          mark[i] = '-';
        }
        //cout << "test : " << mark[i] << endl;
      }
      break;
    }
  }

  // 出力
  for (int i = 0; i < 3; i++)
  {
    cout << Num.at(i) << mark[i];
  }
  cout << Num.at(3) << "=7" << endl;

  return 0;
}