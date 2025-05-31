#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long N, M;
  cin >> N >> M;
  // N: 壁の数, M: 砲台の数

  vector<pair<int, int>> cannon(M);
  // cannon[i].first: 左限界, cannon[i].second: 右限界
  for (int i = 0; i < M; i++)
  {
    cin >> cannon[i].first >> cannon[i].second;
  }
  sort(cannon.begin(), cannon.end());
  // 砲台の左限界でソート

  /*
  壁を守る砲台の数が最小の壁を探す
  */
  vector<int> wall(N + 1, 0);
  wall[0] = INT_MAX; // これまでの最小値
  // wall[i]: 壁iを守る砲台の数
  for (int i = 0; i < M; i++)
  {
    if (wall[cannon[i].first - 1] < wall[0])
    { // 左限界より左の壁はこれ以上更新されない
      wall[0] = wall[cannon[i].first - 1];
      if (wall[0] == 0)
      {
        break; // 壁を守る砲台の最小値が0にならば、これ以上調べる必要はない
      }
    }
    for (int j = cannon[i].first; j <= cannon[i].second; j++)
    {
      wall[j]++;
      if (j == N)
      {
        if (wall[N] > wall[0])
        {
          break;
          // 壁Nを守る砲台の数が最小値を超えたら、これ以上調べる必要はない
        }
      }
    }
  }

  cout << min(wall[N], wall[0]) << endl;
}