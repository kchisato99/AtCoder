#include <bits/stdc++.h>

using namespace std;

#define maxcost 1000000000

int jumpFrog(vector<int> h, int N, int pos, int cost);

int main()
{
  /*
  N個の足場, i番目の足場の高さはhi
  足場1にカエルがいる, カエルは足場iからi+1またはi+2へジャンプする
  ジャンプ先をjとすると, コスト|hi - hj|を支払う
  足場Nにたどり着くまでのコストの総和の最小値を求める
  */
  int N;
  cin >> N;
  vector<int> h(N);
  for (int i = 0; i < N; i++)
  {
    cin >> h.at(i);
  }

  int cost = jumpFrog(h, N - 1, 0, 0);
  cout << cost << endl;
}

// カエルが足場Nに辿り着くまでに払うコストの総和を求める
int jumpFrog(vector<int> h, int N, int pos, int cost)
{
  int tmp, min_cost = maxcost;
  // かえるが足場Nにいる
  if (pos == N)
  {
    return cost; // 総和を返す
  }
  else if (pos < N)
  {
    // pos+i(1or2)にジャンプする
    for (int i = 1; i <= 2; i++)
    {
      if (h.at(pos) < h.at(pos + i)) // |hi - hj| が負の数
      {
        tmp = cost + h.at(pos + i) - h.at(pos);
      }
      else
      {
        tmp = cost + h.at(pos) - h.at(pos + i);
      }
      tmp = jumpFrog(h, N, pos + i, tmp); // Nに辿り着くまでのコストを求める
      if (tmp < min_cost)
      { // 足場Nに辿り着く
        // コストの総和が最小のものを返す
        min_cost = tmp;
      }
    }
    return min_cost;
  }
  return maxcost;
}