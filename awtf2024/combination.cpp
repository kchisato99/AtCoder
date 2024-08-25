#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

struct slime
{
  vector<int> a; 
  int weight;
  int R = 0;
  int L = 0;
  int speed = 0;
};

template<typename T>
vector<vector<T>> combination(vector<T> &elems, int r) {
    vector<vector<T>> v{};
    vector<T> v1(r);
    int n = elems.size();
    function<void(int,int,int)> _dfs = [&](int bit,int now,int num_decided){
        if (num_decided == r) {
            int index = 0;
            for(int i=0; i<n;i++){
                if(bit&(1<<i)){
                    v1[index] = elems[i];
                    index++;
                }
            }
            v.push_back(v1);
            return;
        }
        if(now == n)return;
        _dfs(bit+(1<<now),now+1,num_decided+1);
        _dfs(bit,now+1,num_decided);
    };
    _dfs(0,0,0);
    return v;
}

int main()
{
    int N=5,R=2;
    cin >> N >> R;
    vector<int> elems(N);

    for (int i = 0; i < N; i++) {
        cin >> elems[i];
    }

    struct slime slimes[R];
    
    vector<vector<int>>c = combination(elems, R);
    for(auto i: c){
        for(char j: i){
            cout << j <<" ";
            slimes[i] = j;
        }
        cout << endl;

    }
	return 0;
}
