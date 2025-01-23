#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, A, B;
  cin >> N >> A >> B;
  int Big = 0;

  for (int i = 1; i <= N; i++)
  {
    int sum = 0;
    for (int j =i; j;)
    {
      sum = sum + j % 10;
      j = j / 10;
    }
    if (sum >= A && sum <= B)
    {
      Big = Big + i;
    }
  }
  cout << Big << endl;
}