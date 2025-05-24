#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> A(7);
  for (int i = 0; i < 7; i++)
  {
    cin >> A.at(i);
  }

  /*
  7枚のカードA(7)
  A[i]は1~13の整数
  */
  sort(A.begin(), A.end());
  for (int i = 0; i < 7 - 5; i++)
  {
    if (A.at(i) == A.at(i + 1))
    {
      // 前半で2カード成立
      if (A.at(i) == A.at(i + 2))
      {
        // 前半で3カード成立, 後半で2カード成立すればフルハウス
        for (int j = i + 3; j < 7 - 1; j++)
        {
          if (A.at(j) == A.at(j + 1) && A.at(j) != A.at(i))
          {
            // 後半で2カード成立, よってフルハウス
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
      else
      {
        // 前半は2カードのみ, 後半で3カード成立すればフルハウス
        for (int j = i + 2; j < 7 - 2; j++)
        {
          if (A.at(j) == A.at(j + 1) && A.at(j) == A.at(j + 2))
          {
            // 後半で3カード成立, よってフルハウス
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "No" << endl;
}