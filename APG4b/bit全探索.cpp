#include <bits/stdc++.h>

using namespace std;

int main()
{
  // 　ビット全検索
  //  3bit のbit列をすべて列挙する
  for (int bit = 0; bit < (1 << 3); bit++) // 2のk乗の値を得る 1 << k
  {
    bitset<3> s(bit); //bit をbit列として解釈して
    //bitset<3>型の変数s を初期化
    
    cout << s << endl; // ビット列の出力
  }
  /*
  for(int bit =0; bit < (1 << ビット数); bit++)
  {
    bitset<ビット数> s(bit);
    （ビット列sに対する処理）
  }
  */
}