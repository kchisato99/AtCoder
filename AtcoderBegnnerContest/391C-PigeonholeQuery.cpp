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
  for (int i = 0; i < N; i++)
  {
    hatoP.at(i) = i;
  }

  vector<int> query(Q);
  for (int i = 0; i < Q; i++)
  {
    cin >> query.at(i);
    if (query.at(i) == 1) // 処理
    {
      int P, H;
      cin >> P >> H;
      move_hato(hatoP, P, H);
    }
    else if (query.at(i) == 2) // 出力
    {
      cout << count_hato(hatoP) << endl;
    }
  }
}

void move_hato(vector<int> &hato, int P, int H)
{
  hato.at(P - 1) = H - 1;
}

int count_hato(vector<int> &hato)
{
  set<int> H;
  sort(hato.begin(), hato.end());
  for (int i = 0; i < hato.size(); i++)
  {
    H.insert(hato.at(i));
  }
  return hato.size() - H.size();
}
/*
// 重複している巣の個数を数える
int count_hato(vector<int> &hato)
{
  int count = 0;
  vector<int> H(hato.size());
  for (int i = 0; i < hato.size(); i++)
  {
    H.at(i) = 0;
  }
  for (int i = 0; i < hato.size(); i++)
  {
    if (H.at(hato.at(i)) < 2)
    {
      H.at(hato.at(i))++;
      if (H.at(hato.at(i)) == 2)
      {
        count++;
      }
    }
  }
  return count;
}*/