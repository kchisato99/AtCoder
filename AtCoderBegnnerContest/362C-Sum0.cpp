#include <bits/stdc++.h>

using namespace std;

void orzero(vector<vector<int>> point, vector<int> &x, int p)
{// p作業する場所　up繰り上がりが起きた場所
  int sum = 0;
  if (x.at(p) > point.at(p).at(1))
  {
    x.at(p) = point.at(p).at(0);
    x.at(p+1)++;
    orzero(point, x, p+1);
  }
  else
  {
    for (int i = 0; i < x.size(); i++)
    {
      sum += x.at(i);
    }
    if (sum == 0)
    {
      for (int i = 0; i < x.size(); i++)
      {
        cout << x.at(i) << " ";
      }
      cout << endl;
    }
    else
    {
      x.at(p)++;
      orzero(point, x, p);
    }
  }
}

int main()
{
  // 入力
  int N;
  cin >> N;
  vector<vector<int>> point(N, vector<int>(2));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cin >> point.at(i).at(j); // point.at(i).at() 0はL,1はR
    }
  }

  // 処理
  // 最小値<=0&&最大値>=0のとき, 総和の0になる数列Xiが存在する
  int min = 0, max = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      if (j == 0)
      {
        min += point.at(i).at(j);
      }
      else if (j == 1)
      {
        max += point.at(i).at(j);
      }
    }
  }

  if (min > 0 || max < 0)
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
    vector<int> X(N);
    for (int i = 0; i < N; i++)
    {
      X.at(i) = point.at(i).at(0);
    }
    orzero(point, X, 0);
  }
}