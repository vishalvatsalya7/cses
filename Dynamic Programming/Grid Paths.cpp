#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
int dp[1111][1111];
int main()
{
    fast
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    dp[0][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1][j-1]=='.'){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][n] << endl;
}