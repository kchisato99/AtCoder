#include <bits/stdc++.h>
using namespace std;

int main() {
  /*
  N個の文字列S[i] (1 <= i <= N)
  すべての要素が1以上N以下, 長さKの数列A[i](1 <= i <= K)
  f(A[i]) = S[A[1]] + ... + S[A[K]]  のとき, (+ は文字列の連結)
  N^K個の数列すべてについてf(A[i])を調べたとき, 辞書順に小さいほうからX番目の文字列を求める
  */

  int N, K, X;
  cin >> N >> K >> X;
  vector<string> S(N);

}