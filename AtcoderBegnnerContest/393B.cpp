#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
  string abc;
  cin >> abc;

  /*
  A, B, Cが等間隔に並んでいる場所が何か所あるか調べる
  1. 1<=i<j<k<=|S|
  2. j-i = k-j
  3. S[i] = A
  4. S[j] = B
  5. S[k] = C
  をすべて満たすものの個数
  */

  int count = 0;
  for (int i = 0; i < abc.size() - 2; i++)
  {
    if (abc.at(i) == 'A')
    {
      for (int j = i+1; j < abc.size() - 1; j++)
      {
        if (abc.at(j) == 'B')
        {
          int k = j - i + j;
          if (k < abc.size())
          {
            if (abc.at(k) == 'C')
            {
              count++;
            }
          }
        }
      }
    }
  }
  cout << count << endl;
}