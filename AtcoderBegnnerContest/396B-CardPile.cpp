#include <bits/stdc++.h>

using namespace std;

int main()
{
  vector<int> cards(200); // 0と書かれた100枚の山札
  int top = 0;       // 山札の一番上の位置
  while(top < 100)
  {
    cards.at(top) = 0;
    top++;
  }
  /*
  0の書かれた100枚のカードの山札がある
  以下のクエリを処理する
  クエリの処理
  1: xの書かれたカードを山の一番上に積む
  2: 一番上のカードを取り除き, 書かれた整数を出力する
  */
  int Q; // クエリ数 1<=Q<=100
  cin >> Q;
  vector<int> query(Q);
  for (int i = 0; i < Q; i++)
  {
    cin >> query.at(i);
    if (query.at(i) == 1) {
      top++;
      cin >> cards.at(top);
    }else if(query.at(i) == 2){
      cout << cards.at(top) << endl;
      top--;
    }
  }
}