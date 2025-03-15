#include <bits/stdc++.h>

using namespace std;

int main()
{
  string S;
  cin >> S;
  //reverse(S.begin(), S.end());
  //cout << S << endl;
  /*
  2文字のとき, oo oi io ii
  oo -> ioio 2
  oi -> ioio 2
  io -> 0
  ii -> ioio 2
  */
  vector<int> io_count(3); // 挿入すべきo, 挿入すべき1, prev(o0, i1)
  io_count.at(0) = 0;
  io_count.at(1) = 0;
  io_count.at(2) = 0;
  for (int i = 0; i < S.size(); i++)
  {
    if (S.at(i) == 'i')
    { // i番目にiがきた
      if (io_count.at(2) == 1)
      { // i-1番目がi ii
        io_count.at(2) = 1;
        io_count.at(0)++;
      }
      else if (io_count.at(2) == 0)
      { // i-1番目がi oi
        io_count.at(2) = 1;
      }
      if(i == S.size() - 1)
        {
          io_count.at(0)++;
        }
    }
    else if (S.at(i) == 'o')
    { // i番目にoがきた
      if (io_count.at(2) == 0)
      { // i-1番目がo oo
        io_count.at(2) = 0;
        io_count.at(1)++;
      }
      else if (io_count.at(2) == 1)
      { // i-1番目がi io
        io_count.at(2) = 0;
      }
    }
    //cout << "test : " << S.at(i) << " " << io_count.at(0) << " " << io_count.at(1) << " " << io_count.at(2) << endl;
  }

  cout << io_count.at(0) + io_count.at(1) << endl;
}
