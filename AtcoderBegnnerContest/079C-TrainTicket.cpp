#include <bits/stdc++.h>

using namespace std;

int main()
{
  // 入力
  int X, A, B, C, D;
  cin >> X;
  A = X / 1000;
  X = X % 1000;
  B = X / 100;
  X = X % 100;
  C = X / 10;
  X = X % 10;
  D = X;
  char op[3];

  for (int i = 0; i <= 1; i++)
  {
    for (int j = 0; j <= 1; j++)
    {
      for (int k = 0; k <= 1; k++)
      {
        int sum = 0;
        if (i == 0)
        {
          sum = A + B;
          op[0] = '+';
        }
        else if (i == 1)
        {
          sum = A - B;
          op[0] = '-';
        }
        if (j == 0)
        {
          sum = sum + C;
          op[1] = '+';
        }
        else if (j == 1)
        {
          sum = sum - C;
          op[1] = '-';
        }
        if (k == 0)
        {
          sum = sum + D;
          op[2] = '+';
        }
        else if (k == 1)
        {
          sum = sum - D;
          op[2] = '-';
        }
        if (sum == 7)
        {
          cout << A << op[0] << B << op[1] << C << op[2] << D << "=7" << endl;
          return 0;
        }
      }
    }
  }

  
}