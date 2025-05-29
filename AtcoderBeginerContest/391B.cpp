#include <bits/stdc++.h>

using namespace std;

int main()
{
  /*
  N*NのグリッドS, M*MのグリッドT
  S[i, j], T[i, j]はそれぞれ白色'.'または黒色'#'
  Sの中からTを探す U[a,b] 1<=a,b<=N-M+1
  */
  // 入力
  int N, M; // 1<=N,M<=50
  cin >> N >> M;

  vector<vector<char>> S(N, vector<char>(N));
  vector<vector<char>> T(M, vector<char>(M));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> S.at(i).at(j);
    }
  }

  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> T.at(i).at(j);
    }
  }

  // 処理
  // Sの中からTを探す U[a,b] 1<=a,b<=N-M+
  for(int a = 0; a <= N-M; a++)
  {
    for(int b = 0; b <= N-M; b++)
    {
      bool match = true;
      for(int i = 0; i < M; i++)
      {
        for(int j = 0; j < M; j++)
        {
          if(S.at(a+i).at(b+j) != T.at(i).at(j))
          {
            match = false;
          }
        }
      }
      if(match)
      {
        cout << a+1 << " " << b+1 << endl;
        return 0;
      }
    }
  }
}