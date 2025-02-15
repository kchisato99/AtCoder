#include <bits/stdc++.h>

using namespace std;

int main()
{
  string S1, S2; // S1 高橋, S2 青木
  cin >> S1 >> S2;

  /*
  4種類のカキ1,2,3,4 のうち1種類のカキでおなかを壊す
  高橋S1が1,2 青木が1,3をたべる
  Sickのとき おなかを壊す
  fineのとき おなかを壊さない
  どれが当たりか調べる
  */
  if (S1 == S2)
  {
    if (S1 == "sick")
    {
      cout << "1" << endl;
    }else {
      cout << "4" << endl;
    }
  }else {
    if (S1 == "sick")
    {
      cout << "2" << endl;
    }else {
      cout << "3" << endl;
    }
  }
}