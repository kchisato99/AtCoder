#include <bits/stdc++.h>

using namespace std;

int main()
{
  float X;
  cin >> X;

  if (X < 37.5)
  {
    cout << 3 << endl; //"平熱" << endl;
  }
  else if (X >= 38.0)
  {
    cout << 1 << endl; //"高熱" << endl;
  }
  else
  {
    cout << 2 << endl; //"発熱" << endl;
  }
}