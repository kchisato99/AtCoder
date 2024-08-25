#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a;
  cin >> a;

  int b[4];
  for (int i = 0; a > 0; i++)
  {
    b[i] = a % 10;
    a = a / 10;
    if(i >= 2) {
      if(b[i-2] == b[i] && b[i-1] == b[i]) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}