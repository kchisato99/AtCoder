#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> A(N);
  map<int, int> mp;
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
    mp[A.at(i)]++; // 数A[i]を持っている人の数
  }

  int max_num = 0;
  int max_man = -1;
  for(int i = 0; i < N; i++) {
    if(A.at(i) > max_num && mp[A.at(i)] == 1) {
      max_num = A.at(i);
      max_man = i + 1;
    }
  }
  cout << max_man << endl;
}

  /*
  1からN の番号のついたN人の人
  人[i]は数A[i]を持っている
  「自分と同じ数を持っている人がN-1人の中に存在しない」
  を満たす人のうち, 持っている数が最大の人を求める
  */

  /*
  int max_num = 0;
  int max_man = 0;
  for (int i = 0; i < N; i++)
  {
    bool dab = false;
    for (int j = 0; j < N; j++)
    {
      if (!dab)
      { // ダブれば処理しない
        if (A.at(i) == A.at(j))
        {
          // ダブった
          dab = true;
        }
        if (j == N - 1)
        {
          // 人[i]が条件を満たす
          if (max_num < A.at(i)) {
            max_num = A.at(i);
            max_man = i + 1;
          }
        }
      }
    }
  }

  // 持っている数が最大(max_num)である人(max_man)を出力
  // 存在しない場合は, -1
  cout << max_man -1 << endl;
}*/