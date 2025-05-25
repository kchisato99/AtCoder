#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;

  //  ボタンA  tの末尾に0を追加

  /*  ボタンB  tのすべての数字を次の数字に置き換える
  0から8の数字は+1の数字に置き換え
  9は0に置き換え
  */

  // tを空文字列から文字列sに一致させるために必要なボタンを押す回数
  int total = s[0] - '0' + 1;
  //cout << "初期値:" << total << endl;
  for (int i = 1; i < s.size(); i++)
  {
    total++;
    if (s[i] <= s[i - 1])
    {
      //total += s[i] - s[i - 1];
    }
    else if (s[i] > s[i - 1])
    {
      total += 10;
    }
  }
  cout << total << endl;
}