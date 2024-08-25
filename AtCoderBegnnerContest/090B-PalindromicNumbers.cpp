#include <bits/stdc++.h>
using namespace std;

int main()
{
  // A~Bの間の整数
  int A, B;
  cin >> A >> B;
  int num[5];
  int count = 0;
  for (int i = A; i <= B; i++)
  {
    int a = i;
    for (int j = 0; j < 5; j++)
    {
      num[j] = a % 10;
      a = a / 10;
    }
    if (num[0] == num[4] && num[1] == num[3])
    {
      count++;
    }
  }
  cout << count << endl;
}