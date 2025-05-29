#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> a(M);
  for (int i = 0; i < M; i++)
  {
    cin >> a.at(i);
  }

  /*
  長さMの整数列a[M], 1<=a[i]<=N 重複なし
  a[i]の要素を除いたN以下の整数
  */
  sort(a.begin(), a.end());
  set<int> b;
  int ap = 0;
  for (int i = 1; i <= N; i++)
  {
    if (i != a.at(ap))
    {
      b.insert(i);
    }
    else if (i == a.at(ap))
    {
      if (ap < a.size()-1)
        ap++;
    }
  }

  cout << b.size() << endl;
  for (const auto &elem : b)
  {
    cout << elem << ' ';
  }
  cout << endl;
}