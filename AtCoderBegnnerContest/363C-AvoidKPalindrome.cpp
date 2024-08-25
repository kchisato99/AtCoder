#include <bits/stdc++.h>
#include <string>
#include <algorithm>

using namespace std;

int Palindrome(string T, int N, int K);

int main()
{
  int N, K;
  cin >> N, K;
  string T;
  cin >> T;

  cout << N - Palindrome(T, N, K) << endl;
}

int Palindrome(string T, int N, int K)
{
  string rT = T;
  reverse(rT.begin(), rT.end());
  vector<bool> letter(N);
  for (int i = 0; i < N; i++)
  {
    letter.at(i) = false;
  }
  for (int i = 0; i < N / 2; i++)
  {
    if (equal(T.at(i), T.at(i + K), rT.at(i)))
    {
      for (int j = i; j < i + K; j++)
      {
        letter.at(j) = true;
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < N; i++)
  {
    if (letter.at(i) == true)
      sum++;
  }
  return sum;
}
/*
  vector<bool> letter(T.size());
  for (int i = 0; i < T.size(); i++)
  {
    letter.at(i) = false;
  }
  int start = 0;
  for (int end = T.size(); start < end; end--)
  {
    for (int i = 0; start + i < end - i; i++)
    {
      if (T[start + i] == T[end - i])
      {
        letter.at(start + i) = true;
        letter.at(end - i) = true;
      }
    }
  }
  for (int end = T.size(); start < end; start++)
  {
    for (int i = 0; start + i < end - i; i++)
    {
      if (T[start + i] == T[end - i])
      {
        letter.at(start + i) = true;
        letter.at(end - i) = true;
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < T.size(); i++)
  {
    if (letter.at(i)==true)
      sum++;
  }
  return sum;
}*/
