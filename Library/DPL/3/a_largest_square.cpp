#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int getLargestSquare(vector<vector<int>> & G){
    int h = G.size(),w = G[0].size();
    vector<vector<int>> dp(h,vector<int>(w));
    int maxWidth = 0;

    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            dp[i][j] = (G[i][j]+1)%2;
            maxWidth |= dp[i][j];
        }
    }
    for(int i = 1;i < h;i++){
        for(int j = 1;j < w;j++){
            if(G[i][j]) dp[i][j] = 0;
            else{
                dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                maxWidth = max(maxWidth,dp[i][j]);
            }
        }
    }
    return maxWidth*maxWidth;
}

int main(void){
    int h,w;
    cin >> h >> w;
    vector<vector<int>> G(h,vector<int>(w));

    rep(i,h) rep(j,w) cin >> G[i][j];

    cout << getLargestSquare(G) << endl;

    return 0;
}
