#include <bits/stdc++.h>
using namespace std;

int main()
{
  // 1 <= N <= 200000
  // -N <= R, C <= N
  int N, R, C;
  cin >> N >> R >> C;
  string S;
  cin >> S;
  /*
  無限に広い2次元グリッド
  (0,0)に焚火
  時刻t=0 のとき, (0,0)にのみ煙が存在
  長さNの文字列S, S[i] = N, W, S, E
  */
  // 煙が移動する最大範囲はそれぞれの方向にS.size()だけ
  vector<vector<vector<bool>>> smoke(S.size()+1,vector<vector<bool>>((2 * S.size()) + 2, vector<bool>((2 * S.size()) + 2, false)));
  //(0,0)の位置を (S.size(), S.size())にする
  smoke[0][S.size()][S.size()] = true;

  // S[t]がXであるときの処理
  for (int t = 0; t < S.size(); t++)
  {
    /* test
    for (int i = 0; i <= 2 * S.size(); i++)
    {
      for (int j = 0; j <= 2 * S.size(); j++)
      {
        cout << smoke[t][i][j] << " ";
      }
      cout << endl;
    }
    cout << "---------------------------------------" << endl;
    */
    // 時刻t+0.5 のとき(R,C)の煙の状態
    if (smoke[t][R + S.size()][C + S.size()])
    {
      cout << 1;
    }
    else
    {
      cout << 0;
    }

    if (S[t] == 'N')
    { // t文字目が'N'
      // (r, c)の煙が(r-1, c)に移動する
      for (int r = 0; r <= 2 * S.size(); r++)
      {
        for (int c = 0; c <= 2 * S.size(); c++)
        {
          if (smoke[t][r][c])
          {
            smoke[t+1][r - 1][c] = true;
          }
        }
      }
    }
    else if (S[t] == 'W')
    { // t文字目が'W'
      // (r, c)の煙が(r, c-1)に移動する
      for (int r = 0; r <= 2 * S.size(); r++)
      {
        for (int c = 0; c <= 2 * S.size(); c++)
        {
          if (smoke[t][r][c])
          {
            smoke[t+1][r][c-1] = true;
          }
        }
      }
    }
    else if (S[t] == 'S')
    { // t文字目が'S'
      // (r, c)の煙が(r+1, c)に移動する
      for (int r = 0; r <= 2 * S.size(); r++)
      {
        for (int c = 0; c <= 2 * S.size(); c++)
        {
          if (smoke[t][r][c])
          {
            smoke[t+1][r + 1][c] = true;

          }
        }
      }
    }
    else if (S[t] == 'E')
    { // t文字目が'E'
      // (r, c)の煙が(r, c+1)に移動する
      for (int r = 0; r <= 2 * S.size(); r++)
      {
        for (int c = 0; c <= 2 * S.size(); c++)
        {
          if (smoke[t][r][c])
          {
            smoke[t+1][r][c+1] = true;
          }
        }
      }
    }
      smoke[t+1][S.size()][S.size()] = true;
  }
  // 時刻t+0.5 のとき(R,C)の煙の状態
  if (smoke[S.size()][R + S.size()][C + S.size()])
  {
    cout << 1 << endl;
  }
  else
  {
    cout << 0 << endl;
  }
}