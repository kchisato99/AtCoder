#include <bits/stdc++.h>

using namespace std;

int main()
{
  int h, w; // h行w列のグリッド
            // 上からi行目,左からj列目のマスを(i, j)と表す
  cin >> h >> w;

  // すべてのマスでそのマスに辺で隣接するマスの個数を求める
  // |x1 - x2| + |y1 - y2| = 1 が成り立つとき辺で隣接する
  vector<vector<int>> grid(h, vector<int>(w, 0));
  for (int i = 0; i < h; i++)
  { // 上からi行目
    for (int j = 0; j < w; j++)
    { // 左からj列目
      if (i > 0 && i < h - 1)
      {
        // 上からi行目のマスは上下のマスと辺で隣接する
        grid[i][j] += 2;
      }
      else if (h == 1) {
        // グリッドの行数が1のとき、上下のマスは存在しない
      }else
      {
        grid[i][j]++;
      }
      if (j > 0 && j < w - 1)
      {
        // 左からj行目のマスは左右のマスと辺で隣接する
        grid[i][j] += 2;
      }
      else if (w == 1){
        // グリッドの列数が1のとき、左右のマスは存在しない
      }else
      {
        grid[i][j]++;
      }
    }
  }

  // 出力
  for(int i = 0; i  < h; i++) {
    for(int j = 0; j < w; j ++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}