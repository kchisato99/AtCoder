#include <bits/stdc++.h>

using namespace std;

int main()
{
  // 黒板に整数Xが書いてある
  // Q個のクエリが与えられる
  /*
  与えられるi個目のクエリ
  2つの整数ai, biが与えられる
  黒板に新たに整数ai,biを書く
  黒板に書かれた2i+1個の整数の中央値を出力する
  */

  int X, Q;
  cin >> X >> Q;

  vector<int> ans(Q);
  multiset<int> board;

  for(int i = 0; i < Q; i++) {
    int a, b;
    cin >> a >> b;
    board.insert(a);
    board.insert(b);

    auto it = board.begin();
    advance(it, board.size() / 2);

    ans[i] = *it;
  }

  for (auto a : ans)
  {
    cout << a << endl;
  }
}