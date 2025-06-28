#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;

  /*
  Sが条件を満たしているか判定
  Sの先頭でない大文字の直前の文字はすべてTに含まれる
  2 <= i <= S.size() の整数iについて,
  Sのi番目の文字が大文字ならば, Sのi-1番目の文字はTに含まれる
  */

  bool ans = true;
  for(int i = 1; i < S.size(); i++) {
    if(isupper(S[i]) && find(T.begin(), T.end(), S[i-1]) == T.end()) {
      ans = false;
      break;
    }
  }

  if(ans) {
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }
}