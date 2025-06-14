#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, Q;
  cin >> N >> Q;

  vector<int> X(Q);
  for (auto &x : X)
  {
    cin >> x;
  }
  /*
  N個の箱がある. 最初はすべて空
  Q個のボールがやってくる
  数列X(Q)に従ってボールを箱に入れる
  i番目のボールに以下の処理
    X[i] >= 1 のとき
      X[i]番目の箱にボールを入れる
    X[i] == 0 のとき
      入っているボールが少ないもののうち,　番号が最小の箱に入れる
  それぞれのボールをどの箱に入れたか求める
  */

  vector<int> box(N, 0); // N個の箱, 要素はボールの個数

  for (int i = 0; i < Q; i++)
  {
    if (X[i] >= 1)
    {
      box[X[i] - 1]++; // X[i]番目の箱にボールを入れる
    }
    else if (X[i] == 0)
    {
      int min_index = 0; // 最小値のアドレス
      for(int j = 1; j < N; j++) {
        if(box[j] < box[min_index]) {
          min_index = j; // 最小値を更新
        }
      }
      box[min_index]++; // 最も少ない箱に入れる
      X[i] = min_index + 1; // 出力のために更新
    }
  }

  for(auto &x : X)
  {
    cout << x << " "; // どの箱に入れたか出力
  }
  cout << endl;
}