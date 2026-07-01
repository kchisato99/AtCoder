#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a;
  // a枚の1円玉と無限の500円玉で
  // n円をぴったりにできるか
  cin >> n >> a;

  if(n % 500 <= a) {
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }

}