#include<bits/stdc++.h>

using namespace std;

int main() {
  string s; // 英子文字2N+1以上の長さ
  int n; // 正の整数

  // sの先頭と末尾からn文字ずつ取り除いて得られる文字列の長さを求める
  cin >> s >> n;

  for(int i = n; i < s.size() -n; i++) {
    cout << s[i];
  }
  cout << endl;

}