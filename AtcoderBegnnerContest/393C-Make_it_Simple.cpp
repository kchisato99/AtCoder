#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200000
#define MAX_M 500000

struct peak // 頂点の構造体
{
  int point[MAX_N]; // 辺で接続される先の頂点
  int p=0; // 頂点に接続する辺の数
};

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> left(M), right(M);
  vector<peak> part(N);
  for (int i = 0; i < M; i++)
  {
    cin >> left.at(i) >> right.at(i);
    part[left.at(i)].point[part[left.at(i)].p] = right.at(i);
    part[left.at(i)].p++;
    part[right.at(i)].point[part[right.at(i)].p] = left.at(i);
    part[right.at(i)].p++;
  }

  /*
  N頂点M辺の無効グラフ　辺iは頂点u[i]とright[i]を結ぶ辺
  グラフから辺を取り除いて単純にするためには少なくとも何本の辺を取り除く必要があるか
  自己ループや多重辺を含まない
  */
  /*
  left[i] == left[j]&& right[i] == right[j]
  left[i] == right[j]&& right[i] == left[j]
  */
  /*
  left[i] == N &&
   */
  int count =0;
  for(int i=0; i < N; i++) {
    sort(part[i].point[0], part[i].point[part[i].p]);
    for(int j=1; j < part[i].p; j++) {
      if(part[i].point[j]== part[i].point[j-1]) {
        count++;
      }
    }
  }

  cout << count/2 << endl;
}