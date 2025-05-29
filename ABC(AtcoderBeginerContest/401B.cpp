#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  string S[N];

  bool login = false;
  for (int i = 0; i < N; i++)
  {
    cin >> S[i];
  }

  int ans = 0;
  for (int i = 0; i < N; i++)
  {
    if (S[i] == "login")
    {
      login = true;
    }
    else if (S[i] == "logout")
    {
      login = false;
    }
    else if (S[i] == "public")
    {
    }
    else if (S[i] == "private")
    {
      if (!login)
      { // 認証エラー
        ans++;
      }
    }
  }
  cout << ans << endl;
}