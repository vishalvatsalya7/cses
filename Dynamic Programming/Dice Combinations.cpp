#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
const int mod = 1e9+7;
int dp[1000007];
int solve(int n){
    if(n==0){
        return 1;
    }
    if(dp[n]>0) return dp[n];
    int ans = 0;
    for(int i=1;i<=6;i++){
        if(n-i>=0)
        ans+=solve(n-i);
        ans%=mod;
    }
    dp[n] = ans;
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int ans = solve(n);
    cout << ans << endl;
}