#include <bits/stdc++.h>
using namespace std;

int main() {
  int a , b;
  cin >> a >> b;

  int x = (a + b) / 2;
  if((a + b) % 2 != 0) {
    x++;
  }
  
  cout << x << endl;
}