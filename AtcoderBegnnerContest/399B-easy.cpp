#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for(int i=0; i <n; i++) {
    cin >> p[i];
  }

  // 順位　は　自分より得点が高い人の人数
  for(int i = 0; i < n; i++) {
    int rank = 1;
    for(int j = 0; j < n; j++) {
      if(p[i] < p[j]) {
        rank++;
      }
    }
    cout << rank << endl;
  }
}