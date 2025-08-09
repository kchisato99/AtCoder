#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;

  string S;
  cin >> S;

  if (N < 3 || S.size() < 3)
  {
    cout << "No" << endl;
    return 0;
  }
  else
  {
    int result = S.compare(N - 3, 3, "tea");
    // cout << N << " " << S.size() << endl;
    cout << (result == 0 ? "Yes" : "No") << endl;
    return 0;
  }
}