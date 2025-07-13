#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getDigit(ll N);
//bool isPalindrome(const string &str);
bool ispal(ll x, ll b);

int main()
{
  ll A, N; // 変換する数値N, 変換後の基数A
  cin >> A >> N;
  /*
  正の整数A,N
  1以上N以下の整数のうち,
  10進法, A進法のどちらでも回文となる整数
  の総和を求める
  */
  ll ans = 0; // 総和

  for (int i = 1; i <= min(N, (ll)9); i++)
  {
    if (ispal(i, A))
    {
      // 10進法でもA進法でも回文のとき
      //cout << i << endl; // デバッグ用
      ans += i;          // 合計に加算
    }
  }

  for (int d = 2; d <= getDigit(N); d++)
  { // Nの桁数を求める
    // d桁の回文を生成
    //cout << "test : pow(10, (d + 1)/ 2) = " << pow(10, (d + 1) / 2) << endl;
    for (ll i = 1; i < pow(10, d / 2); i++)
    {
      string s_half = to_string(i);
      string s_pal;           // 完成した回文
      string r_half = s_half; // 下半分になる部分
      reverse(r_half.begin(), r_half.end());
      if (d % 2 == 0)
      {
        // 偶数桁の時
        s_pal = s_half + r_half;
        ll pal_num = stoll(s_pal);
        if (pal_num <= N && ispal(pal_num, A))
        {
          // A進法でも回文のとき
          //cout << s_pal << endl; // デバッグ用
          ans += pal_num;        // 合計に加算
        }
      }
      else
      {
        // 奇数桁の時
        for (int j = 0; j <= 9; j++)
        {
          s_pal = s_half + to_string(j) + r_half;
          ll pal_num = stoll(s_pal);
          if (pal_num <= N && ispal(pal_num, A))
          {
            // A進法でも回文のとき
            //cout << s_pal << endl; // デバッグ用
            ans += pal_num;        // 合計に加算
          }
        }
      }
    }
  }
  cout << ans << endl; // 結果を出力
}

ll getDigit(ll N)
{
  // Nの桁数を求める
  int digit = 0;
  while (N > 0)
  {
    N /= 10;
    digit++;
  }
  return digit; // 桁数を返す
}
/**
bool isPalindrome(const string &str)
{
  // 文字列が回文かどうかを判定
  string reversedStr = str;
  reverse(reversedStr.begin(), reversedStr.end());
  return str == reversedStr;
}
*/
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
  for (ll i = 0; i < s_digits.size(); i++)
  {
    if (s_digits[i] != s_digits[s_digits.size() - 1 - i])
    {
      is_pal = false; // 回文でない
    }
  }
  return is_pal; // 回文ならtrue, そうでなければfalse
}