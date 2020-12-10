#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,k,n) for(int i = k;i < (n);i++)
typedef long long ll;
typedef pair <int,int> P;
typedef vector<vector<int>> Graph;
const ll MOD = 1e9 + 7;
const int INF = 1e8;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int lcs(string A,string B){
    int a = A.size(),b = B.size();
    vector<vector<int>> dp(a+1,vector<int>(b+1,0));
    rep(i,a){
        rep(j,b){
            if(A[i] == B[j]){
                dp[i+1][j+1] =dp[i][j]+1;
            }
            else{
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    return dp[a][b];
}

int main(void){
    int s1,s2,sd;
    string x1,x2;
    cin >> x1 >> x2;
    s1 = x1.size();
    s2 = x2.size(); 
    sd = abs(s1-s2);
    cout << sd+lcs(x1,x2) << endl;

    return 0;
}