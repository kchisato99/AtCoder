#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;

  vector<vector<char>> a(H, vector<char>(W));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> a.at(i).at(j);
    }
  }

  vector<bool> cH(H), cW(W);
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (a.at(i).at(j) == '#')
      {
        cH.at(i) = true;
        break;
      }
      else if (a.at(i).at(j) == '.' && j == W - 1)
      {
        cH.at(i) = false;
      }
    }
  }
  for (int j = 0; j < W; j++)
  {
    for (int i = 0; i < H; i++)
    {
      if (a.at(i).at(j) == '#')
      {
        cW.at(j) = true;
        break;
      }
      else if (a.at(i).at(j) == '.' && i == H - 1)
      {
        cW.at(j) = false;
      }
    }
  }

  bool printl;
  for (int i = 0; i < H; i++)
  {
    printl = false;
    for (int j = 0; j < W; j++)
    {
      if (cH.at(i) == true && cW.at(j) == true)
      {
        cout << a.at(i).at(j);
        printl = true;
        if (j == W - 1)
        {
          cout << endl;
        }
      }
      /*else if (j == W - 1 && (cH.at(i) != true || cW.at(j) != true))
      {
        cout << endl;
      }*/
    }
    if (printl == true && cW.at(W - 1) == false)
    {
      cout << endl;
    }
  }
}