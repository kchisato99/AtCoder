#include <bits/stdc++.h>

using namespace std;

int main() {
    // 整数の入力
    int a, b;
    // スペース区切りの整数の入力
    cin >> a >> b;

    if((a*b)%2 == 0) {
        cout << "Even\n";
    }else {
        cout << "Odd\n";
    }
    
    return 0;
}