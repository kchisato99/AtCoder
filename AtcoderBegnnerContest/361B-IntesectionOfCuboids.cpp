#include <bits/stdc++.h>

using namespace std;

int main()
{
  // 入力
  int a, b, c, d, e, f,
      g, h, i, j, k, l;
  cin >> a >> b >> c >> d >> e >> f;
  cin >> g >> h >> i >> j >> k >> l;

  // 処理
  /*
  1次元のとき、[a,b]と[c,d]の共通部分が正
  共通部分が0の否定 [a,b]が[c,d]より左もしくは右にあるとき
  if(b<=c || d<=a) 共通部分が0
  3次元の場合、3つの座標すべてで長さが正なら体積は正
  */
  bool V = true;
  // 便宜上ソート
  if (a > d)
    swap(a, d);
  if (b > e)
    swap(b, e);
  if (c > f)
    swap(c, f);
  if (g > j)
    swap(g, j);
  if (h > k)
    swap(h, k);
  if (i > l)
    swap(i, l);
  // 共通領域を調べる
  if (a >= j || d <= g)
  {
    V = false;
  }

  if (b >= k || e <= h)
  {
    V = false;
  }

  if (c >= l || f <= i)
  {
    V = false;
  }

  // 出力
  if (V)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}