#include <bits/stdc++.h>
#include <functional>

using namespace std;

struct slime
{
  vector<vector<int>> a;
  int weight;
  int R = 0;
  int L = 0;
  vector<vector<int>> speed = 0;
};

long long factorial(int n) {
  long long fact =1;
  for(int i= 1; i <= n; i++) {
    fact *= i;
  }
  return fact;
}
long long comblination(int n, int r) {
  return factorial(n) / (factorial(r)*factorial(n-r));
}

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}
//nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n-1, k, f);
}

int main()
{
  /*
  直線状にN匹のスライム, 各スライムの重さは1
  i番目のスライムは座標a[i]
   */

  // 入力
  int N, K;
  cin >> N >> K;
  struct slime slimes[N];
  for (int i = 0; i < N; i++)
  {
    cin >> slimes[i].a;
    slimes[i].weight = 1;
  }
  int MAX = comblination(N, K);
  int sum_t[MAX];
  // 処理
  /*
  K匹のスライムを選び, 選ばなかったスライムを数直線上から除く
  選ばれたスライムは時刻0から
    自分より大きい座標にいるスライムの重さの総和をR,
    小さい座標にいるスライムの重さの総和をL
    速度R-Lで移動
  2匹以上のスライムが同じ座標に移動したとき合体して重さは総和になる
  */
 //nCkの組み合わせに対して処理を実行

  
   int t;
   for (t = 0; K > 1; t++)
   {
     for (int i = 0; i < K; i++)
     {
       slimes[i].a += slimes[i].speed;
       for (int j = 0; j < K; j++)
       {
         if (i != j)
         {
           if (slimes[i].a > slimes[j].a) // iよりjが左にある
           {
             slimes[i].L += slimes[j].weight;
           }
           else if (slimes[i].a == slimes[j].a) // 同じ座標
           {
             slimes[i].weight += slimes[j].weight;
             for (int l = j + 1; l < K; l++)
             {
               slimes[l - 1] = slimes[l];
             }
             K--;
           }
           else if (slimes[i].a < slimes[j].a)
           { // 右にある
             slimes[i].R += slimes[j].weight;
           }
         } // if
       } // for j
       slimes[i].speed = slimes[i].R - slimes[i].L;
     } // for i
   } // for t
   cout << t << endl;
   return 0;
   */
}