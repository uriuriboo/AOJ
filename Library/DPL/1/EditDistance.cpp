#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)


int editdistance(string s1,string s2){
    int a = s1.size(),b = s2.size(),cost;
    vector<vector<int>> dp(a+1,vector<int>(b+1,0));
    rep(i,a+1) dp[i][0] = i;
    rep(i,b+1) dp[0][i] = i;

    rep(i,a){
        rep(j,b){
            if(s1[i] == s2[j]) cost = 0;
            else cost = 1;
            dp[i+1][j+1] = min({dp[i+1][j]+1,dp[i][j+1]+1,dp[i][j]+cost});
        }
    }
    return dp[a][b];
}

int main(void){

    string x1,x2;
    cin >> x1 >> x2;
    cout << editdistance(x1,x2) << endl;

    return 0;
}
