#include <bits/stdc++.h>

using namespace std;

#define MAX_W 10
#define MAX_H 10

bool chain(int x, int y);
void search(int x, int y);

char mapper[MAX_W][MAX_H];
bool reached[MAX_W][MAX_H];

int main()
{
  int sx = 10, sy = 10;
  bool onePiece = true;

  // 入力
  for (int i = 0; i < MAX_W; i++)
  {
    for (int j = 0; j < MAX_H; j++)
    {
      cin >> mapper[i][j];
    }
  }

  // 処理
  for (int i = 0; i < MAX_W; i++)
  {
    for (int j = 0; j < MAX_H; j++)
    {
      if (mapper[i][j] == 'x')
      {
        mapper[i][j] = 'o';
        onePiece = chain(i, j);
        if (onePiece)
        {
          break;
        }
        mapper[i][j] = 'x';
      }
    }
    if (onePiece)
    {
      break;
    }
  }

  // 出力
  if (onePiece)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}

bool chain(int x, int y)
{
  for (int i = 0; i < MAX_W; i++)
  {
    for (int j = 0; j < MAX_H; j++)
    {
      reached[i][j] = false;
    }
  }
  search(x, y);
  for (int i = 0; i < MAX_W; i++)
  {
    for (int j = 0; j < MAX_H; j++)
    {
      if (mapper[i][j] == 'o' && reached[i][j] == false)
      {
        return false;
      }
    }
  }
  return true;
}

void search(int x, int y)
{
  // 迷路の外側か壁の場合は何もしない
  if (x < 0 || MAX_W <= x || y < 0 || MAX_H <= y || mapper[x][y] == 'x')
  {
    return;
  }
  // 以前に到達していたら何もしない
  if (reached[x][y])
  {
    return;
  }

  reached[x][y] = true;

  // 4方向試す
  search(x + 1, y); // 右
  search(x - 1, y); // 左
  search(x, y + 1); // 上
  search(x, y - 1); // 下
}