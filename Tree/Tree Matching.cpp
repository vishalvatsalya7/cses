#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
vector<vector<ll> > A;
vector<ll> dp,dp1;
void dfs(ll s,ll p){
    for(auto x: A[s]){
        if(x==p){
            continue;
        }
        dfs(x, s);
        dp1[s]+=max(dp1[x],dp[x]);
    }
    for(auto x:A[s]){
        if(x==p)
            continue;
        dp[s]=max(dp[s],1+dp1[s]+min(ll(0),dp1[x]-dp[x]));
    }
}
int main() {
 
    ll n;cin>>n;
    A.assign(n+1, vector<ll>());
    dp.assign(n+1, 0);
    dp1.assign(n+1, 0);
    for(ll i=1;i<n;i++){
        ll a,b;
        cin>>a>>b;
 
        A[a].push_back(b);
        A[b].push_back(a);
    }
    dfs(1,-1);
 
    cout<<max(dp[1],dp1[1])<<endl;
    return 0;
}