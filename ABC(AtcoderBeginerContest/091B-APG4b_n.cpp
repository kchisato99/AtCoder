#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  string blue[N];
  for (int i = 0; i < N; i++)
  {
    cin >> blue[i];
  }
  int M;
  cin >> M;
  string red[M];
  for (int i = 0; i < M; i++)
  {
    cin >> red[i];
  }

  string vocabulary[N + M];
  int coin[N + M];
  int vp = 0; 
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j <= vp; j++)
    {
      if (j == vp)
      {
        vocabulary[j] = blue[i];
        coin[j] = 1;
        vp++;
        break;
      }
      else if (vocabulary[j] == blue[i])
      {
        coin[j]++;
        break;
      }
    }
  }
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j <= vp; j++)
    {
      if (j == vp)
      {
        vocabulary[j] = red[i];
        coin[j] = -1;
        vp++;
        break;
      }
      else if (vocabulary[j] == red[i])
      {
        coin[j]--;
        break;
      }
    }
  }
  int max = 0;
  for (int i = 0; i < vp; i++)
  {
    if (max < coin[i])
    {
      max = coin[i];
    }
  }
  cout << max << endl;
}