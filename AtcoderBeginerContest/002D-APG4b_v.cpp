#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> x(M), y(M);
  for(int i = 0; i < M; i++) {
    cin >> x[i] >> y[i];
  }

  // 国会議員の数 N <= 12
  // 人間関係の数 M <= N(N-1)/2
  // 派閥x　の所属人数 gr[i]

  vector<int> gr(N);

  
}