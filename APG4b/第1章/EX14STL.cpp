#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B, C;
  cin >> A >> B >> C;

  int mini = min(A, min(B, C));
  int maxi = max(A, max(B, C));

  cout << maxi - mini << endl;
}