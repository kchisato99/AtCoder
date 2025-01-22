#include <bits/stdc++.h>
using namespace std;

int main()
{
  /*
  N個のボタン, 1個光る
  iが光っているときそのボタンを押すとiが消えaiが光る
  最初は1が光っている, 2が光っているときやめたい
  */
  int N;
  cin >> N;
  int a[N];
  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
  }

  // ボタンには1からNの番号 ボタンi+1番
  bool button[N];
  for (int i = 0; i < N; i++)
  {
    button[i] = false;
  }

  int light[N+1]; //光っているボタンの番号
  light[0] = 0; //最初は1番のボタンが光っている
  for (int i = 0; i < N; i++)
  {
    if (button[light[i]] == false) //ループ検知
    {
      button[light[i]] = true;
      if(a[light[i]]==2) {
        cout << i+1 << endl;
        break;
      }
      light[i+1] = a[light[i]]-1; //ai番のボタンが光る
    }else {
      cout << -1 << endl;
      break;
    }
  }
}
