#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  // n枚のカード
  cin >> n;
  vector<int> a(n);
  // i枚目のカードの数字a[i]
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  sort(a.begin(), a.end(), greater<int>());
  // AliceとBobが交互にカードをとる
  int alice = 0, bob = 0;
  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
    {
      alice += a[i];
    }
    else
    {
      bob += a[i];
    }
  }
  cout << alice - bob << endl;
}