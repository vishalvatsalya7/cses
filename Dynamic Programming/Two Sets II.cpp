#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ar array
#define ff first
#define vi vector<int>
#define vll vector<ll>
#define ss second
#define all(x) x.begin(),x.end()
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vector<ll>, greater<ll>>
#define mod 1000000007
using namespace std;
ll binpow(ll a, ll b, ll m){a %= m;ll res = 1;while (b > 0){if (b & 1) res = res * a % m;a = a * a % m;b >>= 1;}return res;}
/* End of template */

const int mx = 1e5+7;
int n;
vector<vector<int>> dp;
int main(){
    cin >> n;
    int sm = (n*(n+1))/2;
    if(sm%2==1){
        cout<<0<<endl;
        return 0;
    }
    dp.resize(n+1, vector<int>(sm/2+1));
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sm/2;j++){
            dp[i][j] += dp[i-1][j];
            dp[i][j] %=mod;
            if(j>=i){
                dp[i][j] += dp[i-1][j-i];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][sm/2] << endl;
}

