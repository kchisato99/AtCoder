#include <bits/stdc++.h>

using namespace std;

struct man
{
  int p;     // next 次の要素のポインタ
  int value; // value ゼッケン
};

int main()
{
  int N;
  cin >> N;
  vector<man> Bib(N+1);
  Bib[0].p = 0;
  Bib[0].value = 0;
  for (int i = 1; i <= N; i++)
  {
    cin >> Bib[i].p;
  }
  for (int i = 1; i <= N; i++)
  {
    cin >> Bib[i].value;
  }

  /*
  人iはQ[i]のゼッケンをつけている, 人iが見つめている人P[i]はゼッケンQ[P[i]]をつけている
  iのゼッケンをつけている人が見つめている数をS[i]とする
  */
  // S[Q[i]] = Q[P[i]]
  vector<int> S(N+1);
  for (int i = 1; i <= N; i++)
  {
    S.at(Bib[i].value) = Bib[Bib[i].p].value;
  }
  for(int i=1; i <= N; i++) {
    cout << S.at(i) << " ";
  }
  cout << endl;
}

/*for (int i = 0; i < N; i++)
{
  for (int j = 0; j < N; j++)
  {
    if (i + 1 == Bib[j].value)
    {
      //S.at(i) = Bib[Bib[j].p - 1].value;
      cout << Bib[Bib[j].p - 1].value << " ";
      break;
    }
  }
}
for (int i = 0; i < N; i++)
{
  cout << S.at(i) << " ";
}
cout << endl;
}*/