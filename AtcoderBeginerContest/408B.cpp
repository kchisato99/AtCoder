#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A.begin(), A.end());
  set<int> uni_A(A.begin(), A.end());

  cout << uni_A.size() << endl;
  for(auto it = uni_A.begin(); it != uni_A.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;

}