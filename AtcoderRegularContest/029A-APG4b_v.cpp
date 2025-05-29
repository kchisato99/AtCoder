#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cin >> N;

  vector<int> t(N);
  for (int i = 0; i < N; i++)
  {
    cin >> t[i];
  }
  sort(t.rbegin(), t.rend());
  /*
  cout << "Sorted times: ";
  for (int i = 0; i < N; i++)
  {
    cout << t[i] << " ";
  }
  cout << endl;*/

  int pa_t = 0, pb_t = 0;
  for (int i = 0; i < N; i++)
  {
    if (pa_t <= pb_t)
    {
      pa_t += t[i];
    }
    else
    {
      pb_t += t[i];
    }
    // cout << i << " pa:" << pa_t << " pb:" << pb_t << endl;
  }

  cout << max(pa_t, pb_t) << endl;
}