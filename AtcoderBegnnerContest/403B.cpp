#include <bits/stdc++.h>
using namespace std;

int main()
{
  // T はSのうち4文字を?で置き換えた文字列
  string T, U;
  cin >> T >> U;

  for (int i = 0; i <= T.size() - U.size(); i++)
  {
    // cout << "i = " << i << " ";
    for (int j = 0; j < U.size(); j++)
    {
      // test
      // cout << T[i+j];
      if (T[i + j] != '?' && T[i + j] != U[j])
      {
        break;
      }
      if (j == U.size() - 1)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
    //cout << endl;
  }
  cout << "No" << endl;
}
