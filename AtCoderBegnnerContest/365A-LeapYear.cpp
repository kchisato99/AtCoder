#include <bits/stdc++.h>

using namespace std;

int main()
{
  int Y, days;
  cin >> Y;

  if (Y % 4 != 0)
  {
    days = 365;
  }
  else if (Y % 4 == 0 && Y % 100 != 0)
  {
    days = 366;
  }
  else if (Y % 100 == 0 && Y % 400 != 0)
  {
    days = 365;
  }
  else if (Y % 400 == 0)
  {
    days = 366;
  }

  cout << days << endl;
}