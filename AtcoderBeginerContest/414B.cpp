#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  // N個の文字と整数の組(c[], l[])
  vector<pair<char, int>> avec(N);
  for (int i = 0; i < N; i++) {
    cin >> avec[i].first >> avec[i].second;
  }

  // l[i]個の文字c[i]を順に連結させた文字列Sを出力
  string S;
  //int sp = 0; // 文字列の長さ

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < avec[i].second; j++) {
      S += avec[i].first; // c[i]をl[i]回連結
      //sp++;
      if(S.size() > 100) {
        cout << "Too Long" << endl;
        return 0;
      }
    }
    
  }
  cout << S << endl;
}