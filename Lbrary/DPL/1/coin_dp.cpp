#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int INF = 1e8;

int dp(int n,vector<int> &dpv,vector<int> &c){
    int m = c.size();
    dpv[0] = 0;
    rep(i,m){
        for(int j = 0;j+c.at(i) <= n;j++){
            dpv[j+c[i]] = min(dpv[j+c[i]],dpv[j]+1);
        }
    }
    return dpv[n];
}

int main(void){
    int n,m,ans;
    cin >> n >> m;
    vector<int> c(m),dpv(n+1,INF);
    rep(i, m) cin >> c.at(i);
    ans = dp(n,dpv,c);
    cout << ans << endl;
    return 0;
}
