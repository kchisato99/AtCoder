#include <bits/stdc++.h>
using namespace std;

// 比較関数
bool my_compare(tuple<string, int, int> a,
                tuple<string, int, int> b)
{
  // 辞書順で比較
  if (get<0>(a) != get<0>(b))
  {
    return get<0>(a) < get<0>(b);
    // 市名が異なる場合は、辞書順で比較
  }
  if (get<1>(a) != get<1>(b))
  {
    return get<1>(a) > get<1>(b);
    // 同じ市内のレストランは点数が高いものから紹介
  } // 同じ点数はない
  else
  {
    return false;
  }
}

int main()
{
  int N;
  cin >> N;

  /*
  N個のレストランを紹介
  レストランiはS[i]にある
  評価P[i]点, 同じ点数はつかない

  市名を辞書順で紹介
  同じ市内のレストランは点数が高いものから紹介
  */

  vector<tuple<string, int, int>> spot(N);
  for (auto &p : spot)
  {
    cin >> get<0>(p) >> get<1>(p);
    // レストランの番号を保持
    get<2>(p) = &p - &spot[0] + 1; // 1から始まるインデックス
  }

  sort(spot.begin(), spot.end(), my_compare);
  /*
    辞書順にソートされた状態で、
    同じ市内のレストランは点数が高いものから紹介される
  */
  /*
   cout << endl;
   for (auto &p : spot)
   {
     cout << get<0>(p) << " " << get<1>(p)
          << " " << get<2>(p) << endl;
   }
  */

  for (auto &p : spot)
    cout << get<2>(p) << endl;
}