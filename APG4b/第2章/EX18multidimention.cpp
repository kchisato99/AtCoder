#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M; // N人が参加してM試合
  cin >> N >> M;

  vector<int> A(M), B(M); // 試合iで勝った人Ai, 負けた人Bi
  for (int i = 0; i < M; i++)
  {
    cin >> A.at(i) >> B.at(i);
  }

  vector<vector<char>> R(N, vector<char>(N));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      R.at(i).at(j) = '-';
    }
  }

  for (int i = 0; i < M; i++)
  {
    R.at(A.at(i) - 1).at(B.at(i) - 1) = 'o';
    R.at(B.at(i) - 1).at(A.at(i) - 1) = 'x';
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << R.at(i).at(j);
      if (j == N - 1)
      {
        cout << endl;
      }
      else
      {
        cout << " ";
      }
    }
  }
}