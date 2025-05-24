// 深さ優先探索

/*
関数 search(x,y) {
if(場所 (x,y) が壁か迷路の外)
  return;
if(既に (x,y) に一度到達している)
  return;
(x,y) に到達したことを記録
}

//　4方向を試す
search(x+1, y) //右
search(x-1, y) //左
search(x, y+1) //下
search(x, y-1) //上
}
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX_W 500
#define MAX_H 500

void search(int x, int y);

int W, H;                   // 横幅と縦幅
char maze[MAX_W][MAX_H];    // 迷路
bool reached[MAX_W][MAX_H]; // 到達できるか

int main()
{

  int sx = 0, sy = 0, gx = 0, gy = 0;
  cin >> H >> W;
  for (int i = 0; i < W; i++)
  {
    for (int j = 0; j < H; j++)
    {
      cin >> maze[i][j];
      if (maze[i][j] == 's')
      {
        sx = i;
        sy = j;
      }
      else if (maze[i][j] == 'g')
      {
        gx = i;
        gy = j;
      }
    }
  }
  search(sx, sy);

  if (reached[gx][gy])
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}

void search(int x, int y)
{
  // 迷路の外側か壁の場合は何もしない
  if (x < 0 || W <= x || y < 0 || H <= y || maze[x][y] == '#')
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