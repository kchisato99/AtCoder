#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  string T, A;
  cin >> T >> A;

  for(int i=0; i < N; i++) {
    if(T[i]=='o' && A[i]=='o') {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}