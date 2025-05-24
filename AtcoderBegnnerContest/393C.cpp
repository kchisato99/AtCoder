#include <bits/stdc++.h>
#include <map>

using namespace std;

#define MAX_N 200000
#define MAX_M 500000

int main()
{
  int N, M;
  cin >> N >> M;
  map<pair<int, int>, int> m;
  int ans = 0;
  for (int i = 0; i < M; i++)
  {
    int u, v;
    cin >> u >> v;

    /*
    N頂点M辺の無効グラフ　辺iは頂点u[i]とright[i]を結ぶ辺
    グラフから辺を取り除いて単純にするためには少なくとも何本の辺を取り除く必要があるか
    自己ループや多重辺を含まない
    */
    if (u > v)
    {
      swap(u, v);
    }
    if (u == v) // 　辺の両端が同一の頂点
    {
      ans++;
    }
    else if (u != v)
    {
      m[{u, v}]++;
      if (m[{u, v}] > 1) // 同一の頂点を結ぶ辺が複数存在する
      {
        ans++;
      }
    }
  }
  cout << ans << endl;
}