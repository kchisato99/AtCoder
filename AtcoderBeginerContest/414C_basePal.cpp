#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPalindrome(const string &str);
bool ispal(ll x, ll b);

int main()
{
  int A, N; // 変換する数値N, 変換後の基数A
  cin >> A >> N;
  /*
  正の整数A,N
  1以上N以下の整数のうち,
  10進法, A進法のどちらでも回文となる整数
  の総和を求める
  */
  // int b = 10; // 10進法の基数
  vector<ll> vec;
  vector<ll> powb = {1}; //
  ll len = 1;

  while (1)
  {
    while (powb.size() < len)
    {
      ll w = powb[powb.size() - 1] * 10;
      powb.push_back(w);
    }
    if (powb[len - 1] > N)
    {
      break; // Nを超えたら終了
    }

    vector<ll> d((len + 1) / 2, 0); // d[i]は回文のi桁目の数字
    // 上半分. d[0]は最上位桁
    d[0] = 1;

    while (1)
    {
      ll sum = 0;
      for (int i = 0; i < len; i++)
      {
        ll idx;
        if (i < d.size())
        {
          idx = d[i];
        }
        else
        {
          idx = (len - 1) - i;
        }
        sum += powb[i] + d[idx];
      }
    }
  }

  for (int i = 1; i <= N; i++)
  {
    string i_str = to_string(i);
    if (isPalindrome(i_str))
    {
      // 10進法で回文のとき
      // iをA進法に変換して回文かどうか判定
      if (ispal(i, A))
      {
        // A進法でも回文のとき
        ans += i; // 合計に加算
      }
    }
  }
  cout << ans << endl; // 結果を出力
}

bool isPalindrome(const string &str)
{
  // 文字列が回文かどうかを判定
  string reversedStr = str;
  reverse(reversedStr.begin(), reversedStr.end());
  return str == reversedStr;
}

bool ispal(ll x, ll b)
{
  // xをb進数に変換して回文かどうか判定
  // ----- 基数変換 -----
  vector<ll> s_digits; // s[i]は b進数のi桁目の数字
  while (x > 0)
  {
    s_digits.push_back(x % b);
    x /= b;
  }
  // ----- 回文判定 -----
  bool is_pal = true;
  for (int i = 0; i < s_digits.size() / 2; i++)
  {
    if (s_digits[i] != s_digits[s_digits.size() - 1 - i])
    {
      is_pal = false; // 回文でない
    }
  }
  return is_pal; // 回文ならtrue, そうでなければfalse
}