#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;
  /*
  T個のテストケース
  各テストケースはN個のドミノ

  N個のドミノ
  ドミノiの大きさはS[i]
  ドミノiが倒れるとき, 次のドミノの大きさが2*S[i]以下ならば倒れる
  一番左のドミノは1
  一番右のドミノはN
  倒しきるドミノの並びが存在するか
  存在する場合, 最小は何個のドミノか
  */
  int case_num = 0;
  vector<int> ans(T);
  while (T--)
  {
    // cout << "Case " << case_num << "開始" << endl;
    int N;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++)
    {
      cin >> S[i];
    }
    ans[case_num] = 1; // ドミノ0はすでに配置されている

    sort(S.begin() + 1, S.end() - 1);
    // 中間のドミノをソートする
    // S[0], S[N-1]はソートの対象外
    for (int i = 1; i < N; i++)
    {
      // S[i-1]のドミノが倒れる
      // ドミノN-1が直接倒せるなら終了
      if (S[N - 1] <= 2 * S[i - 1])
      {
        // ドミノN-1が倒せる
        ans[case_num]++;
        case_num++;
        break;
      }

      // ドミノN-1が倒れない場合
      // 中間に配置するドミノを探す
      if (S[i] <= 2 * S[i - 1])
      {
        // 倒れるドミノが存在する
        for (int j = i + 1; j < N; j++)
        {
          // 条件を満たす最大のドミノを探す
          if (S[j] > 2 * S[i - 1])
          {
            // ドミノjが倒れないとき, ドミノj-1までが倒れる
            i = j - 1;
            break;
          }
        }
        // 中間にS[i]を配置する
        ans[case_num]++;
      }
      else
      {
        // 倒せるドミノがない
        // ドミノN-1は倒せないかつ差し込むドミノもない
        // あきらめて終了
        ans[case_num] = -1;
        case_num++;
        break;
      }
    }
  } // 次のテストケースへ

  for (int i = 0; i < case_num; i++)
  {
    cout << ans[i] << endl;
  }
}