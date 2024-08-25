#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main()
{
  // 入力
  vector<vector<int>> point(3, vector<int>(2));
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cin >> point.at(i).at(j);
    }
  }
  vector<int> length(3);
  length.at(0) = std::pow(point.at(0).at(0) - point.at(1).at(0), 2) + std::pow(point.at(0).at(1) - point.at(1).at(1), 2);
  length.at(1) = std::pow(point.at(0).at(0) - point.at(2).at(0), 2) + std::pow(point.at(0).at(1) - point.at(2).at(1), 2);
  length.at(2) = std::pow(point.at(2).at(0) - point.at(1).at(0), 2) + std::pow(point.at(2).at(1) - point.at(1).at(1), 2);
  sort(length.begin(), length.end());
  if(length.at(0)+length.at(1)==length.at(2)) {
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }

}