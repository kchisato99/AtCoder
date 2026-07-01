#include <bits/stdc++.h>
using namespace std;

int main() {
  int r ,g;
  cin >> r >> g;

  // g = (r + score) / 2
  int score = 2 * g - r;

  cout << score << endl;
}