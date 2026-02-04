#include <bits/stdc++.h>

using namespace std;

int main()
{
  // 入力
  int D;
  long long G; // D:問題数<=10, G:目標スコア
  cin >> D >> G;

  vector<int> p(D), c(D);
  for (int i = 0; i < D; i++)
  {
    cin >> p[i] >> c[i];
  }

  // 処理
  int ans = INT_MAX;
  // まず、完答ボーナスを考える
  // 少なくとも完答すれば、目標に到達する組み合わせを考える
  for (int bit = 0; bit < (1 << D); bit++)
  {
    bitset<10> comp(bit);
    long long score = 0;
    int num = 0;
    // 完答する場合の点数を出す
    for (int i = 0; i < D; i++)
    {
      if (comp.test(i))
      {
        score += 100 * (i + 1) * p[i] + c[i];
        num += p[i];
      }
    }
    //cout << "test1: score" << score << " num " << num  << " : " << comp << endl;

    if (score >= G) // スコアを超えていた場合、最小の問題数を更新する
    {
      ans = min(ans, num);
    }
    else
    {
      // 完答だけでスコアが足りない場合, 細かい点数を追加する
      // 1問あたりの点数が高い後ろから考える
      for (int i = D - 1; i >= 0; i--)
      {
        // すでに完答しているのでスルーする
        if (comp.test(i))
        {
          continue;
        }
        for (int j = 0; j < p[i] - 1; j++)
        {
          score += 100 * (i + 1);
          num++;
          if (score >= G)
          {
            break;
          }
        }
        //cout << "test2: score" << score << " num " << num << " : " << comp << endl;
        if (score >= G)
          break;
      }
      if (score >= G)
      {
        ans = min(ans, num);
      }
    }
  }
  cout << ans << endl;
}