#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N;

  vector<int> A(N);
  for(auto &a : A) {
    cin >> a;
  }
  cin >> K;

  /*
  N個のレース
  i番目のレースはA[i]歳以下が参加できる
  K歳の馬が参加できるレースの数を求める
  */

  int count =0;

  for(int i= 0; i < N; i++) {
    if(A[i] >= K) {
      count++;
    }
  }

  cout << count << endl;

}