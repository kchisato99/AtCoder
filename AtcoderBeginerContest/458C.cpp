#include <bits/stdc++.h>

using namespace std;

int main() {
  string s; // 英大文字からなる文字列
  cin >> s;

  /* 
  条件を満たす部分文字列の個数を求める
  ・奇数個の文字からなる
  ・中央の文字がCである(部分文字列がl文字からなるとき(l+1)/2文字目がC)
  */

  // Cの位置を中央としたとき、存在できる部分文字列の数を調べる
  long long ans = 0;

  for(int i = 0; i < s.size(); i++) {
    // i文字目がCであるとき
    if(s[i] == 'C') {
      // 0とi, iとs.size()-1を比較して小さいほうとiの差+1が存在できる部分文字列の数
      ans += min(i, (int)s.size() -1 -i) + 1;
    }
  }

  cout << ans << endl;
}