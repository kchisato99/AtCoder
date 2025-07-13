#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, L, R;
  cin >> N >> L >> R;

  vector<int> X(N), Y(N);
  for(int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }

  int listeners = 0;
  for(int i = 0; i < N; i++) {
    if(X[i] <= L && R <= Y[i]) {
      listeners++;
    }
  }
  cout << listeners << endl;

}