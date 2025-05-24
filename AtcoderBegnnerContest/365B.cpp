#include <bits/stdc++.h>
//#include <vector>

using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<vector<int>> A(N, vector<int>(2));
  for(int i=0; i < N; i++) {
    cin >> A.at(i).at(0);
    A.at(i).at(1) = i;
  }
  
  sort(A.begin(), A.end());

  cout << A.at(N-2).at(1)+1 << endl;
}