#include <bits/stdc++.h>
using namespace std;

int main() {
  double N, S;
  cin >> N >> S;

  vector<double> T(N);
  for(int i = 0; i < N; i++) {
    cin >> T[i];
  }

  bool wakeup = true;
  double total_time = 0.0;
  for(int i= 0; i < N; i++) {
    if(T[i]-total_time >= S+0.5) {
      wakeup = false;
      break;
    }else {
      total_time = T[i];
    }
  }

  if(wakeup) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

}