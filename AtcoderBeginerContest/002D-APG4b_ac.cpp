#include <bits/stdc++.h>

using namespace std;

int main()
{
  // 入力
  // N人の国会議員, M個の人間関係(x, y)
  int N, M, x, y;
  cin >> N >> M;
  // 国会議員iはjとつながりがある
  bool con[N][N] = {};
  for (int i = 0; i < M; i++)
  {
    cin >> x >> y;
    con[x - 1][y - 1] = con[y - 1][x - 1] = true;
  }

  // 処理
  int ans = 0;
  // 派閥を作成できる議員の組み合わせを考える
  for (int bit = 0; bit < (1 << N); bit++)
  {
    bitset<12> gr(bit);
    bool ok = true;

    // デバッグ用メッセージ
    //cout << "test : " << gr << endl;
    // 議員xが, (議員yとつながっている)
    for (int i = 0; i < N; i++)
    {
      if (gr.test(i))
      {
        for (int j = 0; j < i; j++)
        {
          if (gr.test(j) && !con[i][j])
          {
            //cout << " 議員" << i+1 << "は議員" << j+1 << "を知らない" << endl;
            ok = false;
            break;
          }
        }
      }
      if (!ok)
      {
        break;
      }
    }
    // 派閥が作成可能ならば人数を更新する
    if (ok)
    {
      //cout << "派閥は" << gr.count() << "人" << endl;
      ans = max(ans, (int)gr.count());
    }
  }

  // 出力
  cout << ans << endl;
}