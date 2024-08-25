#include <bits/stdc++.h>

using namespace std;

int main()
{
  // 入力
  int R, G, B;
  cin >> R >> G >> B;
  // 高橋君の嫌いな色
  string C;
  cin >> C;
  if(C == "Red") {
    cout << min(G,B) << endl;
  }else if(C == "Green") {
    cout << min(R, B) << endl;
  }else if(C == "Blue") {
    cout << min(R, G) << endl;
  }
}