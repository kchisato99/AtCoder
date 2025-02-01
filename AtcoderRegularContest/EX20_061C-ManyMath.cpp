/*
ビット全検索
組み合わせの全列挙
すべてのビット列の組み合わせに対して処理を行う
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  string S;
  cin >> S;
  int N = S.size();
  long res = 0;

  for (int bit = 0; bit < (1 << (N-1)); bit++) // bit全検索
  {
    long tmp = 0;
    for (int i = 0; i < N - 1; i++)
    {
      tmp *= 10;
      tmp += S[i] - '0';
      if (bit & (1 << i))
      {
        res += tmp;
        //cout << tmp << " ";
        tmp = 0;
      }
    }
    tmp *= 10;
    tmp += S.back() - '0';
    //cout << tmp << " ";
    res += tmp;
    //cout << res << endl;
  }
  cout << res << endl;
}