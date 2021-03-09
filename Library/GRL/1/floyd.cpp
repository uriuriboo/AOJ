#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
const ll lINF = 1e18;

void floyd(vector<vector<ll> > &d){
    int n = d.size();
    for(int k = 0;k < n;k++){
        for(int i = 0;i < n;i++){
            if(d[i][k] == lINF) continue;
            for(int j = 0;j < n;j++){
                if(d[k][j] == lINF) continue;
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main(void){
    int n,e,u,v,c;
    cin >> n >> e;
    vector<vector<ll> > d(n,vector<ll>(n));
    rep(i,n){
        rep(j,n){
            d[i][j] = ( (i==j) ? 0 :lINF);
        }
    }

    rep(i,e){
        cin >> u >> v >> c;
        d[u][v] = c;
    }
    floyd(d);
    bool negative = false;

    rep(i,n) if(d[i][i] < 0) negative = true;

    if(negative) cout << "NEGATIVE CYCLE" << endl;

    else{
        rep(i,n){
            rep(j,n){
                if(j) cout << " ";
                if(d[i][j] == lINF) cout << "INF";
                else cout << d[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
