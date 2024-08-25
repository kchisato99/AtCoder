#include <bits/stdc++.h>
using namespace std;

int main()
{
  // Xの各桁の和でXが割り切れる場合ハーシャッド数
  int X;
  cin >> X;

  int sum = 0;
  int a = X;
  while (a)
  {
    sum = sum + a % 10;
    a = a / 10;
  }
  // cout << sum <<" " <<X%sum << endl;
  if (X % sum == 0)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}