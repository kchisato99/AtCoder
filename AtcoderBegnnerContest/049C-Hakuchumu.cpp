#include <bits/stdc++.h>
using namespace std;

string devide[4] = {"dream", "dreamer", "erase", "eraser"};

int main()
{
  string S;
  cin >> S;

  reverse(S.begin(), S.end());
  for (int i = 0; i < 4; i++)
  {
    reverse(devide[i].begin(), devide[i].end());
  }

  bool can = true;
  for (int i = 0; i < S.size();)
  {
    bool can2 = false; // divede(分割)できるか
    for (int j = 0; j < 4; j++)
    {
      string d = devide[j];
      if (S.substr(i, d.size()) == d)
      {
        can2 = true;
        i += d.size();
      }
    }

    if (!can2)
    { // divide(分割)できなかった
      can = false;
      break;
    }
  }

  if (can)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}