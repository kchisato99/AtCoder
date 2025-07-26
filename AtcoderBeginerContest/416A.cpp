#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, L, R;
  cin >> N >> L >> R;

  string S;
  cin >> S;

  for(int i = L; i <= R; i++) {
    if(S[i-1] == 'o') {
      if(i == R) {
        cout << "Yes" << endl;
        return 0;
      }
    }else {
      cout << "No" << endl;
      return 0;
    }
  }
}