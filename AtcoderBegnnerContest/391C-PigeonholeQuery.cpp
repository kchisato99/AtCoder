#include <bits/stdc++.h>

using namespace std;

void move_hato(vector<int> &hato, int P, int H);
int count_hato(vector<int> &hato);

int main()
{
  // 鳩ノ巣原理
  /*
  N匹の鳩 1~N番 2<=N<=10^6
  N個の巣 1~N番
  はじめ, 鳩iは巣iにいる

  Q個のクエリが与えられる 1<=Q<=3*10^5
   1 P H: 鳩Pを巣Hに移動させる
   2 : 複数の鳩がいる巣の個数を出力
  */

  // 入力
  int N, Q;
  cin >> N >> Q;

  vector<int> hatoP(N); // 鳩Pがいる巣i
  vector<int> Home(N);  // 巣iにいる鳩の数
  for (int i = 0; i < N; i++)
  {
    hatoP.at(i) = i;
    Home.at(i) = 1;
  }
  int count = 0;

  vector<int> query(Q); // クエリ
  for (int i = 0; i < Q; i++)
  {
    cin >> query.at(i);
    if (query.at(i) == 1) // 処理
    {
      int P, H;
      cin >> P >> H;

      Home.at(hatoP.at(P - 1))--; // 元いた巣から鳩を移動
      if (Home.at(hatoP.at(P - 1)) == 1)
      {
        count--;
      }

      hatoP.at(P - 1) = H - 1;
      Home.at(H - 1)++; // 移動先の巣に鳩を移動
      if (Home.at(H - 1) == 2)
      {
        count++;
      }
      /*
      for (int i = 0; i < N; i++)
      {
        cout << Home.at(i) << " ";
      }
      cout << endl;
      */
    }
    else if (query.at(i) == 2) // 出力
    {
      cout << count << endl;
    }
  }
}