/*
 最初のN個の大文字でラベルの付いたN個のボールがある
 どの2つのボールも重さが異なる
 Q回クエリを質問できる
 各クエリでは2つのボールの重さを比べることができる
 ボールを軽い順にソートする
*/

#include <cstdio>
#include <string>

using namespace std;

int main()
{
  // 整数の入力
  int N, Q, j;
  scanf("%d%d", &N, &Q);
  // Q回以下のクエリを質問する

  // 最初のN個の大文字
  string s;
  for (int i = 0; i < N; i++)
  {
    s += (char)('A' + i);
  }

  for (int i = 0; i < N; i++)
  {
    for (j = 0; j < N - 1; j++)
    {
      // s1とs2は異なる最初のN個の大文字のどれか
      printf("? %c %c\n", s[j], s[j + 1]);
      fflush(stdout);
      // クエリの答え ansは<または>
      char ans;
      scanf(" %c", &ans);
      if (ans == '>')
      {
        swap(s[j], s[j + 1]);
      }
    }
  }
  // ! ans N文字の文字列
  printf("! %s\n", s.c_str());
  fflush(stdout);

  return 0;
}
