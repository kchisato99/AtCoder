#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;

  vector<vector<int>> gr(12, vector<int>(12));
  vector<int> x(M), y(M);
  for (int i = 0; i < M; i++)
  {
    cin >> x[i] >> y[i];
    gr[x[i] - 1][y[i] - 1] = 1;
    gr[y[i] - 1][x[i] - 1] = 1; // 無向グラフなので両方向に辺を張る
  }

  // 国会議員の数 N <= 12
  // 人間関係の数 M <= N(N-1)/2
  // 派閥x　の所属人数 gr[i]

  int ans = 1;
  for (int i = 0; i < (1 << N); i++)
  { // bit全探索
    vector<int> as;
    // 派閥のメンバーを格納する配列
    for (int j = 0; j < N; j++)
    { // j番目のビットが立っているかどうか
      if (1 & (i >> j))
      {                  // j番目のビットが立っているならば
        as.push_back(j); // jを派閥に追加
      }
    }

    bool ok = true; // 派閥が成立するかどうか
    for (int j = 0; j < as.size(); j++)
    {
      for (int k = j + 1; k < as.size(); k++)
      {
        if (i == j)
          continue; // 自分自身は除外
        if (gr[as[j]][as[k]] == 0)
        {
          ok = false; // 人間関係がないので派閥は成立しない
        }
      }
    }

    if (ok)
    {
      ans = max(ans, (int)as.size()); // 派閥の人数を更新
    }
  }
  cout << ans << endl;
}