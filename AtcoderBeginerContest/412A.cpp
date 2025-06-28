#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N), B(N);
  for(int i =0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  
  /*
  i日目にA[i]個のタスク完了が目標
  実際にはB[i]個のタスクが完了
  目標より多くタスクを完了した日数
  */

  int ans = 0;
  for(int i = 0; i < N; i++) {
    if(B[i] > A[i]) {
      ans++;
    }
  }
  cout << ans << endl;
}