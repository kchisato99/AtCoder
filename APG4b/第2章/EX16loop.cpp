#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> data(5);
  for (int i = 0; i < 5; i++)
  {
    cin >> data.at(i);
  }

  // dataの中で隣り合う等しい要素が存在するなら"YES"を出力し、そうでなければ"NO"を出力する
  bool judge = false;
  for (int i = 0; i < 5; i++)
  {
    if (i < 5 - 1 && data.at(i) == data.at(i + 1))
    {
      judge = true;
    }
    if (i > 0 && data.at(i) == data.at(i - 1))
    {
      judge = true;
    }
  }

  if(judge) {
    cout << "YES" << endl;
  }else {
    cout << "NO" << endl;
  }
}