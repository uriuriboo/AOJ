#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,k,n) for(int i = k;i < (n);i++)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
using ll = long long;
using P = pair<ll,ll>;
#define repl(i,n) for(ll i = 0;i < (n);i++)
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll lINF = 1e18;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template <class T> inline bool chmin(T &a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b) {a = b; return true;} return false;}

int lis(vector<int> &a){
    int n = a.size();
    vector<int> l(n);
    l[0] = a[0];
    int length = 1;
    for(int i = 1;i < n;i++){
        if(l[length-1] < a[i]) l[length++] = a[i];
        else *lower_bound(l.begin(),l.begin()+length,a[i]) = a[i];
    }
    return length;
}

int main(void){
    int n,ans = 0;
    cin >> n;
    vector<int> a(n),l(n);
    rep(i, n) cin >> a[i];

    cout << lis(a) << endl;

    return 0;
}