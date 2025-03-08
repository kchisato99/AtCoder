#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }

  /*
  長さNの整数列Aが与えられる
  同じ要素が３つ以上連続する箇所があるか調べる
  */
  for (int i = 0; i < N-2; i++)
  {
    if (A.at(i) == A.at(i + 1) && A.at(i) == A.at(i + 2))
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}