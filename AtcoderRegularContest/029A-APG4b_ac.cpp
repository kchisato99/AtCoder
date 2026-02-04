#include <bits/stdc++.h>

using namespace std;

int main()
{
  // 入力
  int N; // 肉の数 0<=N<=4
  cin >> N;
  vector<int> t(N); // 肉iを焼くのにかかる時間
  for(int i = 0; i < N; i++) {
    cin >> t[i];
  }

  //処理
  int ans = INT_MAX;
  // 肉の数が4しかないので, すべての組み合わせを試す
  for(int bit = 0; bit < (1 << N); bit++) {
    bitset<4> cook(bit);
    int timeA = 0, timeB = 0;
    for(int i=0; i < N; i++) {
      if(cook.test(i)) {
        timeA += t[i];
      }else {
        timeB += t[i];
      }
    }
    ans = min(ans, max(timeA, timeB));
  }

  // 出力
  cout << ans << endl;
}