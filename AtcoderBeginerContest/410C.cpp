#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, Q; // Q個のクエリ
  cin >> N >> Q;

  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    A[i] = i + 1;
  }

  vector<vector<int>> query(Q, vector<int>(3, 0));
  for (int i = 0; i < Q; i++)
  {
    cin >> query[i][0];
    if (query[i][0] == 1)
    {
      cin >> query[i][1] >> query[i][2];
    }
    else if (query[i][0] == 2 || query[i][0] == 3)
    {
      cin >> query[i][1];
    }
  }

  /*
  長さNの整数列A(N), 当初A[i] = i
  Q個のクエリが与えられる
  クエリは以下の3種類
    1. A[p] を x に更新する
    2. A[p] の値を出力する
    3. 「Aの先頭の要素を末尾にする」をk回繰り返す
        Aを(A[1], A[2],...,A[N-1],A[0])に置き換えるをk回繰り返す
  クエリの形式
    1. 1 p x
    2. 2 p
    3. 3 k
  */
  int offset = 0;
  for (int i = 0; i < Q; i++)
  {
    // cout << "てすと" << i+1<< endl;
    int p = query[i][1] - 1;
    if (query[i][0] == 1)
    {
      A[(p + offset) % N] = query[i][2];
      // A[query[i][1] - 1] = query[i][2];
    }
    else if (query[i][0] == 2)
    {
      cout << A[(p + offset) % N] << endl;
      // cout << A[query[i][1] - 1] << endl;
    }
    else if (query[i][0] == 3)
    {
      offset = (offset+p+1) % N;
      /*
      // k回繰り返す. kだけスライドさせる
      int k = query[i][1] % N;
      if (k != 0)
      {
        vector<int> tmp(k);
        for (int j = 0; j < k; j++)
        {
          tmp[j] = A[j];
        }

        for (int j = 0; j < N - k; j++)
        {
          A[j] = A[j + k];
        }
        for (int j = 0; j < k; j++)
        {
          A[j + N - k] = tmp[j];
        }
      }*/
    }
    /* test
    cout << i + 1 << "test :";
    for (int p = 0; p < N; p++)
    {
      cout << A[p] << " ";
    }
    cout << endl;*/
  }
}