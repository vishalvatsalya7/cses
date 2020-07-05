#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
int dp[1000007];
int solve(int n){
    if(n==0) return 0;
    if(dp[n]>0) return dp[n];
    int ans = INT_MAX;
    int x = n;
    while(n>0){
        int r = n%10;
        if(r>0)
        ans = min(ans, 1+solve(x-r));
        n/=10;
    }
    dp[x] = ans;
    return ans;
}
int main()
{
    fast
    int n;
    cin >> n;
    int ans = solve(n);
    cout << ans << endl;
}