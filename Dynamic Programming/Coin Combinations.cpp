#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
int dp[1000007];
int solve(int n, int nn, vector<int>& a){
    if(n==0){
        return 1;
    }
    if(dp[n]!=-1) return dp[n];
    int ans=0;
    for(int i=0;i<nn;i++){
        if(n-a[i]>=0){
            ans+=solve(n-a[i],nn,a);
            ans%=mod;
        }
    }
    return dp[n]=ans;
}
int main()
{
    fast
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto& w:a){
        cin >> w;
    }
    for(int i=0;i<=x;i++) dp[i]=-1;
    int ans = solve(x,n,a);
    cout<< ans<< endl;
}