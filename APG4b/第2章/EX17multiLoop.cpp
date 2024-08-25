#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, S;
  cin >> N >> S;
  vector<int> A(N), P(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++)
  {
    cin >> P.at(i);
  }

  // リンゴ・パイナップルをそれぞれ1つずつ購入するとき合計S円になるような買い方が何通りあるか
  // ここにプログラムを追記
  int currect = 0;
  int sum = 0;
  for (int i = 0; i < N; i++)
  { // リンゴ
    for (int j = 0; j < N; j++)
    { // パイナップル
      if (A.at(i) + P.at(j) == S)
      {
        currect++;
      }
    }
  }

  cout << currect << endl;
}
