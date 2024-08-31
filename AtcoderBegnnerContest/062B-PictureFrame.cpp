#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W; // 縦H, 横W
  cin >> H >> W;

  string S[H];
  for (int i = 0; i < H; i++)
  {
    cin >> S[i];
  }

  for (int i = 0; i < W + 2; i++)
  {
    cout << "#";
  }
  cout << endl;

  for (int i = 0; i < H; i++)
  {
    cout << "#" << S[i] << "#" << endl;
  }
  
  for (int i = 0; i < W + 2; i++)
  {
    cout << "#";
  }
  cout << endl;
}