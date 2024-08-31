#include <bits/stdc++.h>
using namespace std;

int main() {
	// 現在のレーティングa, パフォーマンスb
	// レーティングはaとbの平均まで変化
	// c = (a+b)/2
	// → b = 2c - a
  int R, G, b;
  cin >> R >> G;
	// 現在のレーティングR のとき, Gまで変化させたい
	// 取るべきパフォーマンスb を求める
	b = (2*G)- R;
  cout << b << endl;
  
}