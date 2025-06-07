#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> A(N);
  // map<int, int> cnt;

  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  sort(A.rbegin(), A.rend()); // Aの要素を降順にソート
  // A[i]以上の要素がi個以上現れる
  for (int i = N; i > 0; --i)
  {
    // x以上の要素がx個以上現れるのは,
    // A[x] >= x が成り立つとき
    if (A[i - 1] >= i)
    {
      cout << i << endl;
      return 0;
    }
  }
  cout << 0 << endl; // どのxに対しても条件を満たさない場合は0を出力
}