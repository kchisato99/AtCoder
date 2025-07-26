#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  // . # からなる文字列S
  /*
  条件をすべて満たす文字列Tのうち, o の文字数が最大となるもの
  1. T と Sは同じ長さである
  2. T　は, . # o のみからなる
  3. S[i] = # のときに限り T[i] = # である
  4. T[i] = T[j] = o　(i<j) ならば,
    T[i+1],...,T[j+1]の中に # が１つ以上存在する
  */

  bool can_o = true;
  string T(S.size(), '.');
  for (int i = 0; i < S.size(); i++)
  {
    if (S[i] == '#')
    {
      T[i] = '#';
      can_o = true; // # の後はoが可能
    }
    else if (can_o)
    {
      T[i] = 'o';
      can_o = false; // 次のoは#が必要
    }
  }

  cout << T << endl;
}