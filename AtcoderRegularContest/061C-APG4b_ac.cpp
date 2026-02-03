#include <bits/stdc++.h>

using namespace std;

int main()
{
  // 入力
  string S;
  cin >> S;

  //cout << "test" << S.length() << endl;

  // 処理
  long long total = 0;

  for (int bit = 0; bit < (1 << S.length()-1); bit++) // +の入る場所のすべての組み合わせ
  {
    long long sum = 0;
    bitset<9> mark(bit);
    //cout << mark << endl;
    long long val = S[0] - '0';

    for (int i = 1; i < S.length(); i++)
    {
      // +あれば加算, なければ桁上がり
      if (mark.test(i - 1))
      {
        sum += val;
        val = S[i] - '0';
      }
      else
      {
        val = val * 10;
        val += S[i] - '0';
      }
    }
    sum += val;
    total += sum;
    //cout << "test"<< bit << " : " << mark << " " << sum << endl;

  }

  // 出力
  cout << total << endl;

  return 0;
}