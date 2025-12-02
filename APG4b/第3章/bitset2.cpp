#include <bits/stdc++.h>
using namespace std;
int main() {
  bitset<4> S;
  S.set(0, 1);  // 0番目のビットを1にする
  cout << S << endl;

  if (S.test(0)) {
    cout << "1st bit is 1" << endl;
  } else {
    cout << "1st bit is 0" << endl;
  }
  if (S.test(1)) {
    cout << "2nd bit is 1" << endl;
  } else {
    cout << "2nd bit is 0" << endl;
  }
  if (S.test(2)) {
    cout << "3rd bit is 1" << endl;
  } else {
    cout << "3rd bit is 0" << endl;
  }
  if (S.test(3)) {
    cout << "4th bit is 1" << endl;
  } else {
    cout << "4th bit is 0" << endl;
  }
}
