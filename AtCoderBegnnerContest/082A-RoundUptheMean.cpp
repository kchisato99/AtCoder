#include <bits/stdc++.h>
using namespace std;

int main() {
	// 2つの整数a,b 平均値をx
  int a, b;
  cin >> a >> b;
  if((a+b)%2 > 0) {
	cout << ((a+b)/2) + 1 << endl;
  }else {
	cout << ((a+b)/2) << endl;
  }
  
}