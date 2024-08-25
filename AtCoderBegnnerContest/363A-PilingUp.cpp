#include <bits/stdc++.h>

using namespace std;

int main () {
  int R;
  cin >> R;

  int RP = R;
  while(RP>=0) {
    RP -= 100;
  }
  
  cout << - RP << endl;
}