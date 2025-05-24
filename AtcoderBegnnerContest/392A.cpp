#include <bits/stdc++.h>

using namespace std;

#define max(p,q) ((p), (q) ? (p) : (q))

int main() {
  vector<int> A(3);
  cin >> A.at(0) >> A.at(1) >> A.at(2);

  sort(A.begin(), A.end());
  if(A.at(0)*A.at(1)==A.at(2)) {
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }

}