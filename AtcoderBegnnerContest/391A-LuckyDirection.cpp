#include <bits/stdc++.h>

using namespace std;

int main()
{
  // 8方位を表す文字列D
  string D;
  cin >> D;

  // 処理
  if (D.size() == 1)
  {
    if (D.at(0) == 'N')
      cout << "S" << endl;
    else if (D.at(0) == 'E')
      cout << "W" << endl;
    else if (D.at(0) == 'S')
      cout << "N" << endl;
    else if (D.at(0) == 'W')
      cout << "E" << endl;
  }
  else if (D.size() == 2)
  {
    if (D.at(0) == 'N')
    {
      if (D.at(1) == 'E')
        cout << "SW" << endl;
      else if (D.at(1) == 'W')
        cout << "SE" << endl;
    }
    else if (D.at(0) == 'S')
    {
      if (D.at(1) == 'E')
        cout << "NW" << endl;
      else if (D.at(1) == 'W')
        cout << "NE" << endl;
    }
  }
  return 0;
}