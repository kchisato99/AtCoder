#include <bits/stdc++.h>

using namespace std;

int main()
{
  // 文字列 s, t
  string s, t;
  cin >> s >> t;

  /*
  sの部分列かつtの部分列であるような文字列のうち, 最長のものを出力する
  細切れでもいい
  */
  // dp[i][j] sをi文字目, tをj文字目までみたときの最長共通部分の長さ
  vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));

  for (int i = 0; i < s.size(); i++)
  {
    for (int j = 0; j < t.size(); j++)
    {
      if (s.at(i) == t.at(j))
      {
        dp[i + 1].at(j + 1) = dp[i].at(j) + 1;
      }
      else
      {
        dp[i + 1].at(j + 1) = max(dp[i].at(j + 1), dp[i + 1].at(j));
      }
    }
  }
  //cout << dp[s.size()].at(t.size()) << endl;

  int i = s.size(), j = t.size();
  int ans_len = 0;
  string ans;
  
  while (ans_len < dp[s.size()].at(t.size()))
  {
    if (s.at(i-1) == t.at(j-1))
    {
      ans += s.at(i-1); // 文字列の結合
      i--;
      j--;
      ans_len++;
    }
    else if (dp[i].at(j) == dp[i - 1].at(j))
    {
      i--;
    }
    else
    {
      j--;
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}