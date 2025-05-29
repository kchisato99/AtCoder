#include <bits/stdc++.h>
using namespace std;

int main()
{
  float a, b;
  cin >> a >> b;

  float result = a / b;
  int result_int = static_cast<int>(result);
  // cout << result << endl;
  // cout << result_int << endl;
  float sa;
  float sa_plus;
  sa = abs(result - result_int);
  sa_plus = abs(result - result_int - 1);
  if(sa < sa_plus) {
    cout << result_int << endl;
  } else {
    cout << result_int + 1 << endl;
  }
}