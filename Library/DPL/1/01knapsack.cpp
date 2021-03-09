#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,k,n) for(int i = k;i < (n);i++)
typedef long long ll;
typedef pair <int,int> P;
const ll MOD = 1e9 + 7;
const int INF = 1e8;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int rec(int n,int i,int j,vector<int> &v,vector<int> &w,vector<vector<int>> &dp){

    if(dp[i][j] >= 0){ 
        return dp[i][j];
    }
    int res;
    if(i == n) res = 0;

    else if(j < w[i]) res = rec(n,i+1,j,v,w,dp);

    else res = max(rec(n,i+1,j,v,w,dp),rec(n,i+1,j-w[i],v,w,dp)+v[i]);

    return dp[i][j] = res;

}

int main(void){

    int N,W,ans = 0;
    cin >> N >> W;
    vector<int> v(N),w(N);
    vector<vector<int>> dp(N+1,vector<int>(W+1,-1));

    rep(i, N) cin >> v[i] >> w[i];

    cout << rec(N,0,W,v,w,dp) << endl;

    return 0;
}
