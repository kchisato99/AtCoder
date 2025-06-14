#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<pair<int, int>> ab(N);
  for(auto &p : ab)
  {
    cin >> p.second >> p.first;
  }
  /*
  for (int i = 0; i < N; i++)
  {
    cin >> ab[i].second >> ab[i].first;
  }
  /*
    cout << endl;
    for (int i = 0; i < N; i++)
    {
      cout << ab[i].first << " " << ab[i].second << endl;
    }
  */
  sort(ab.begin(), ab.end());
  /*
  cout << endl;
  for (int i = 0; i < N; i++)
  {
    cout << ab[i].second << " " << ab[i].first << endl;
  }
  */

  //cout << endl;
  for (auto &p : ab)
  {
    cout << p.second << " " << p.first << endl;
  }
}
