#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long x, y;
  cin >> x >> y;

  vector<long long> a(10, 0);
  a[0] = x;
  a[1] = y;
  long long tmp;
  for (int i = 2; i < 10; i++)
  {
    tmp = a[i - 1] + a[i - 2];
    while (tmp > 0)
    {
      a[i] = (a[i] * 10) + tmp % 10;
      tmp = tmp / 10;
    }
  }
  /* test
  for (int i = 0; i < 10; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
*/
  cout << a[9] << endl;
}