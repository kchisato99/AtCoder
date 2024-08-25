#include <functional>

#include <bits/stdc++.h>

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f)
{
  if (rest == 0)
  {
    f(indexes);
  }
  else
  {
    if (s < 0)
      return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f)
{
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

int main()
{
  int N, K;
  std::cin >> N >> K;

  foreach_comb(N, K, [](int *indexes)
               {
    for (int i = 0; i < K; i++)
    {
      std::cout << indexes[i] << ",";
    }
    std::cout << std::endl; });
  // std::cout << indexes[0] << ',' << indexes[1] << ',' << indexes[2] << std::endl;
}