#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> a(N);
  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
  }

  map<int, int> countNum; // 値と出現回数の組
  int maxNum = 0;         // 最大出現回数の値
  /*
  for (int i = 0; i < N; i++)
  {
    countNum[a[i]]++;
    if (countNum[a[i]] > countNum[maxNum])
    {
      maxNum = a[i];
    }
  }*/
  for (auto x : a)
  {
    countNum[x]++;
    if (countNum[x] > countNum[maxNum])
    {
      maxNum = x;
    }
  }
  cout << maxNum << " " << countNum[maxNum] << endl;
}