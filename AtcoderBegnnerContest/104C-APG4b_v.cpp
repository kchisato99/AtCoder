#include <bits/stdc++.h>
using namespace std;

int main()
{
  int d, g;
  // 問題の大問数d, 目標の点数g
  cin >> d >> g;

  vector<int> p(d), c(d);
  // p[i]: i番目の大問の問題数, c[i]: i番目の大問のボーナス点
  for (int i = 0; i < d; i++)
  {
    cin >> p[i] >> c[i];
  }

  int res =  1 << 29; // 最小の解答数を求めるための変数
  for (int bit = 0; bit < (1 << d); bit++)
  {              // 全ての大問の解き方をbitで表現
    int sum = 0; // 合計点
    int num = 0; // 解いた大問の数
    for (int i = 0; i < d; i++)
    { // i番目の大問を解くかどうか
      if (bit & (1 << i))
      { // i番目の大問を解く場合
        sum += c[i] + p[i] * 100 * (i + 1);
        // 解いた大問のボーナス点と問題数から得られる点数を加算
        num += p[i];
      }
    }
    if (sum >= g)
    { // 目標点数gを超えた場合
      res = min(res, num);
      // 最小の解答数を更新
    }
    else
    { // 目標点数gを超えない場合
      for (int i = d - 1; i >= 0; --i)
      {
        if (bit & (1 << i))
        { // i番目の大問は既に解いた場合
          continue;
        }
        for (int j = 0; j < p[i]; j++)
        {
          if (sum >= g)
          { // 目標点数gを超えた場合
            break;
          }
          sum += 100 * (i + 1); // i番目の大問の問題を1つ解く
          num++;                // 解答数を1増やす
        }
      }
      res = min(res, num);
      // 最小の解答数を更新
    }
  }
  cout << res << endl; // 最小の解答数を出力
}