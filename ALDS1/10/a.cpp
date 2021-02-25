#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,ans = 0;
    cin >> n;
    vector<int> f(50);
    f[0] = 1;
    f[1] = 1;

    for(int i = 2;i <= n;i++) f[i] = f[i-1]+f[i-2];

    cout << f[n] << endl;


    return 0;
}
