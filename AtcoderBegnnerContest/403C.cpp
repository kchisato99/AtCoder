#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M, Q;
  cin >> N >> M >> Q;
  // ユーザXがページYを閲覧できるか
  vector<vector<bool>> XY(N + 1, vector<bool>(M + 1, false));

  // 3種類のクエリ
  int query_type;
  int user_x, page_y;
  for (int i = 0; i < Q; i++)
  {
    cin >> query_type;
    if (query_type == 1)
    {
      // ユーザXにページYの閲覧権限を付与
      cin >> user_x >> page_y;
      XY[user_x][page_y] = true;
    }
    else if (query_type == 2)
    {
      // ユーザXにすべてのページの閲覧権限を付与
      cin >> user_x;
      XY[user_x][0] = true;
    }
    else if (query_type == 3)
    {
      // ユーザXがページYを閲覧できるか回答
      cin >> user_x >> page_y;
      if (XY[user_x][page_y]|| XY[user_x][0])
      {
        cout << "Yes" << endl;
      }
      else// if (!XY[user_x][page_y] && !XY[user_x][0])
      {
        cout << "No" << endl;
      }
    }
  }
}