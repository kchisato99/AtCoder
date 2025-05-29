#include <bits/stdc++.h>
using namespace std;

int main()
{
  /*
  N個のひなあられ
  4色P, W, G, Y
  i番目の色Si
  3種類の"Three", 4種類"Four"
  */
  int N;
  cin >> N;
  char S[N];
  int Color[4]; // P, W, G, Y

  for (int i = 0; i < 4; i++)
  {
    Color[i] = 0;
  }

  for (int i = 0; i < N; i++)
  {
    cin >> S[i];
    switch (S[i])
    {
    case 'P':
      Color[0]++;
      break;
    case 'W':
      Color[1]++;
      break;
    case 'G':
      Color[2]++;
      break;
    case 'Y':
      Color[3]++;
      break;
    }
  }

  int count = 0;
  for (int i = 0; i < 4; i++)
  {
    if (Color[i] > 0)
    {
      count++;
    }
    //cout << Color[i] << endl;
  }
//cout << count << endl;
  if (count == 3)
  {
    cout << "Three" << endl;
  }
  else if (count == 4)
  {
    cout << "Four" << endl;
  }
}