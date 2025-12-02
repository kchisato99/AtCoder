#include <bits/stdc++.h>
using namespace std;

int main() {
  // 3ビットのビット列をすべて列挙する
  for (int tmp = 0; tmp < (1 << 3); tmp++) {
    // 3ビット左シフトすると、ビット列は「1000」(2の3乗)
    // 2のk乗の値を得るために、1 << k と書く
    bitset<3> s(tmp);
    // ビット列を出力
    cout << s << endl;
  }

  /* ひな形
  for (int tmp = 0; tmp < (1 << ビット数); tmp++) {
  bitset<ビット数> s(tmp);
  // (ビット列sに対する処理)
  }
  */
}
