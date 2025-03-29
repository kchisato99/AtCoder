#include <bits/stdc++.h>

using namespace std;

struct person
{
  int score;
  int rank;
  int order;
};

int main()
{
  int n;
  cin >> n;
  vector<person> p(n);
  for (int i = 0; i < n; i++)
  {
    cin >> p[i].score;
    p[i].order = i;
  }

  /*
  N人, 人[i]の得点p[i]
  順位が決まる
  1. r = 1, N 人の順位はすべて未確定
  2. N　人の順位確定するまで繰り返す
    ・未確定の人の中で得点の最大値x, p[i]= x となる人の人数をl
    　k人をr位と確定させて r += k
  */

  sort(p.begin(), p.end(), [](const person &a, const person &b)
       { return (a.score > b.score); });
  // 順位をつけていく
  for (int r = 0; r < n;)
  {
    int x = p[r].score;
    int k;
    for (k = 0; k < n - r; k++)
    {
      if (p[r + k].score == x)
      {
        p[r + k].rank = r + 1;
      }
      else
      {
        break;
      }
    }
    r += k;
  }

  sort(p.begin(), p.end(), [](const person &a, const person &b)
       { return (a.order < b.order); });

  // ---- debug 出力してみる ----
  for (int i = 0; i < n; i++)
  {
    cout << p[i].rank << endl;
  }
}