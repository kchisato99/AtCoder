#include <bits/stdc++.h>
using namespace std;

void print_vec(vector<int> vec)
{ // 問題文の形式でvec値を出力
  cout << "[ ";
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec.at(i) << " ";
  }
  cout << "]" << endl;
}

string read_name()
{
  // 変数名を読み取りイコールを読み飛ばす
  string name, equal;
  cin >> name >> equal;
  return name;
}

/*
int式の項を1つ読み取る
数字なら値を返し、数字でないなら変数の値を返す
var_int : int の変数を保持するmap
*/
int read_int(map<string, int> &var_int)
{
  string val;
  cin >> val;
  // 条件演算子
  // 条件式 ? 真のとき : 偽のとき
  return isdigit(val.at(0)) ? stoi(val) : var_int.at(val);
}

/*
int 式全体を読み取って計算する
var_int : int の変数を保持するmap
*/
int calc_int(map<string, int> &var_int)
{
  // var_int にはread_intで読みとった変数と値が入っている
  int sum = 0;   // 計算結果を保持する変数
  string s = ""; // 演算子を読み取るための変数

  while (s != ";") // セミコロンが来るまで繰り返す
  {
    int val = read_int(var_int);

    if (s == "")
    {
      // 最初の項を読み取る
      sum = val;
    }
    else if (s == "+")
    {
      sum += val;
    }
    else if (s == "-")
    {
      sum -= val;
    }
    cin >> s; // 演算子を読み取る
  }
  return sum;
}

/*
vec値を読み取る
最初の'['は読み取ってある前提で進める
var_int : int の変数を保持するmap
*/
vector<int> read_vec_val(map<string, int> &var_int)
{
  vector<int> result;
  string symbol = ""; // 演算子を読み取るための変数

  // vec値の最後の']'が来るまで繰り返す
  while (symbol != "]")
  {
    // 数値を読み取ってvec値に追加する
    int val = read_int(var_int);
    result.push_back(val);

    cin >> symbol; // 演算子を読み取る
  }
  return result;
}

/*
vec式の項を1つ読み取る
vec値なら値を返し、vec値でないなら変数の値を返す
var_int : int の変数を保持するmap
var_vec : vec の変数を保持するmap
*/
vector<int> read_vec(map<string, int> &var_int, map<string, vector<int>> &var_vec)
{
  string s;
  cin >> s;
  // "[" ならvec値を読み取る、そうでないなら変数の値を返す
  return s == "[" ? read_vec_val(var_int) : var_vec.at(s);
}

/*
vec式全体を読み取って計算する
var_int : int の変数を保持するmap
var_vec : vec の変数を保持するmap
*/
vector<int> calc_vec(map<string, int> &var_int, map<string, vector<int>> &var_vec)
{
  string symbol;  // 演算子を読み取るための変数
  vector<int> result; // 計算結果を保持する変数
  
  // ; が出てくるまで読み取る
  while (symbol != ";")
  {
    // 項を1つ読み取る
    vector<int> vec = read_vec(var_int, var_vec);

    // 記号が入力されていない場合、結果はそのまま代入
    if (symbol == "")
    {
      result = vec;
    }
    // 足し算の場合
    if (symbol == "+")
    {
      for (int i = 0; i < result.size(); i++)
      {
        result.at(i) += vec.at(i);
      }
    }
    // 引き算の場合
    if (symbol == "-")
    {
      for (int i = 0; i < result.size(); i++)
      {
        result.at(i) -= vec.at(i);
      }
    }
    // symbolには+, -, ; のいずれかが入る
    cin >> symbol; // 演算子を読み取る
  }
  return result;
}

int main()
{
  // 入力
  // 命令の行数を取得
  map<string, int> var_int;         // int の変数を保持するmap
  map<string, vector<int>> var_vec; // vector の変数を保持するmap
  int N;
  cin >> N;

  // 行数分の処理
  for (int i = 0; i < N; i++)
  {
    // 命令を受け取る
    string s;
    cin >> s;

    // int命令の処理
    if (s == "int")
    {
      // 変数名を受け取る
      string name = read_name();
      // 右辺の式を計算して変数に代入
      var_int[name] = calc_int(var_int);
    }

    // vec命令の処理
    if (s == "vec")
    {
      // 変数名を読み取る
      string name = read_name();
      // 右辺の式を計算して変数に代入
      var_vec[name] = calc_vec(var_int, var_vec);
    }

    // print_int命令の処理
    if (s == "print_int")
    {
      // 式を計算して出力
      cout << calc_int(var_int) << endl;
    }

    // print_vec命令の処理
    if (s == "print_vec")
    {
      // 式を計算して出力
      print_vec(calc_vec(var_int, var_vec));
    }
  }
}