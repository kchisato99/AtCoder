#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;

  string S[H];
  for (int i = 0; i < H; i++)
  {
    cin >> S[i];
  }

  for (int i = 0; i < H; i++) // H
  {
    for (int j = 0; j < W; j++) // W
    {
      if (S[i].at(j) != '#')
      {
        int mine = 0;
        for (int k = i - 1; k <= i + 1; k++) // H
        {
          if (k >= 0 && k < H)
          {
            for (int l = j - 1; l <= j + 1; l++) // W
            {
              if (l >= 0 && l < W)
              {
                if (S[k].at(l) == '#')
                {
                  mine++;
                }
              }
            }
          }
        }
        cout << mine;
      }else {
        cout << S[i].at(j);
      }
    }
    cout << endl;
  }

}