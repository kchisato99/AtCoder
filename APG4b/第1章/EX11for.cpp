#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, A;
  cin >> N >> A;

  // ここにプログラムを追記
  // 計算の回数N, 最初の値A

  // 演算子opi 計算する値Bi
  char op[N];
  int B[N];
  
  for (int i = 0; i < N; i++)
  {
    cin >> op[i] >> B[i];
    switch (op[i])
    {
    case '+':
      A = A + B[i];
      break;
    case '-':
      A = A - B[i];
      break;
    case '*':
      A = A * B[i];
      break;
    case '/':
      if (B[i] != 0)
      {
        A = A / B[i];
      }
      else
      {
        cout << "error" << endl;
        return 0;
      }
      break;
    default:
      cout << "error" << endl;
      return 0;
    }
    cout << i + 1 << ":" << A << endl;
  }
}