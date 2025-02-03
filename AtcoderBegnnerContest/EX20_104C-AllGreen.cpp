#include <bits/stdc++.h>

using namespace std;

#define pimax 100
#define Dmax 10

int main()
{
  int D, G; // 1<=D<=10, 100<=G
  int p[Dmax], c[Dmax];

  cin >> D >> G;
  rep(i, 0 , D) {
    cin >> p[i] >> c[i];
  }
  
  // bit全検索
  //if(bit &(1 << i)) はbitのi番目のフラグが立っているかどうかを判定する
  // << 左シフト演算　
  rep(i, 0 , D) {
    rep(j, 0, p[i]) {

    }
  }
}
  /*
  総合スコアをG点以上にするために必要な最小の問題数を求める
  100i点をつけられた問題がp[i]問
  基本スコア:問題の配点の合計
  完答ボーナス:100i点をつけられたp[i]問を全て解いた場合
    に得られるc[i]点のボーナス
  
  // 入力
  //  c[i], G はすべて100の倍数
  int D, G; // 1<=D<=10, 100<=G
  cin >> D >> G;
  vector<int> p(D + 1), c(D + 1);
  p.at(0) = pimax + 1; // 最小の完答ボーナスの問題数
  c.at(0) = 0;
  for (int i = 1; i <= D; i++)
  {
    cin >> p.at(i) >> c.at(i);
    if (100 * p.at(i) + c.at(i) >= G && p.at(i) < p.at(0))
    // 完答ボーナスで解決できる かつ 問題数が最小のとき
    {
      p.at(0) = p.at(i); // 最小の問題数を更新
    }
    cout << "p.at(0):" << p.at(0) << endl;
  }

  if (p.at(0) <= pimax) // 完答ボーナスで解決できるとき, さらに安く済むか検討
  {
    if (p.at(D) > p.at(0)) // 単品より完答ボーナスで先に解決できる
    {
      cout << p.at(0) << endl; // 出力: 完答ボーナスで解決
      return 0;
    }
    else if (p.at(D) < p.at(0)) // 単品のほうが安い可能性がある
    {
      for (int i = 1; i < p.at(0); i++)
      {
        if (100 * i * D >= G)
        { // 100D点をi問解いたときにG点以上になる
          cout << i << endl;
          return 0;
        }
      }
      cout << p.at(0) << endl; // 出力: 完答ボーナスで解決
      return 0;
    }
  }
  else if (p.at(0) > pimax) // 完答ボーナスで解決できないとき
  {
    int ex_min = D;
    int sum = 0;
    // 完答ボーナス + 単品で解決しなければならない
    for (int i = 1; i < D; i++)
    {
      sum = 100 * i * p.at(i) + c.at(i); // p[i]問を全て解いたときのスコア
      for (int j = 0; j < p.at(D); j++)
      {
        if (sum + (100 * j * p.at(D)) >= G && i + j < p.at(0) + ex_min)
        // 完答ボーナス + 単品で解決できる かつ 問題数が最小のとき
        {
          // 最小問題数の更新
          p.at(0) = p.at(i); // 最小問題数のとき, 完答ボーナスに必要な問題数
          ex_min = j;  // 最小問題数のとき, 必要な単品の問題数
        }
      }
    }
    cout << p.at(0) << "+" << ex_min << "=" << p.at(0) + ex_min << endl;
  }
  return 0;
}*/