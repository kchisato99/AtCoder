#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M; // N個の都市, M本の道路
  cin >> N >> M;

  int a[M], b[M];
  /*
  i番目の道路はaiとbiを双方向に結ぶ

  */
 for(int i=0; i < M; i++) {
  cin >> a[i] >> b[i];
 }
int count[N];//都市iからcount[i]本の道路が伸びる
for(int i = 0; i < N; i++) {
  count[i] = 0;
}

for(int i=0; i < M; i++) {
 count[a[i]-1]++;
 count[b[i]-1]++; 
}

for(int i=0; i<N; i++) {
  cout << count[i] << endl;
}

}