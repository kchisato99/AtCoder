#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, a, b;
  cin >> n >> a >> b;
  //  n 時間駐車したとき, a*n 円
  //  b 円固定
  //  n 時間駐車したとき, 最小料金
  if (a * n <= b)
  {
    cout << a * n << endl;
  }
  else
  {
    cout << b << endl;
  }
}