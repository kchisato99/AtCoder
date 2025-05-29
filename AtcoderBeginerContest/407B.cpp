#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x, y;
  cin >> x >> y;

  // int match_x = 0;
  // int match_y = 0;
  double match = 0;

  for (int i = 1; i <= 6; i++)
  { // 1つ目のさいころ
    for (int j = 1; j <= 6; j++)
    {
      if (i + j >= x)
      {
        // match_x++;
        match++;
      }
      else if (abs(i - j) >= y)
      {
        // match_y++;
        match++;
      }
    }
  }
  double ans = match / 36;
  cout << fixed << setprecision(15) << ans << endl;
}