#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
 
int main()
{
    fast
    string s,t;
    cin >> s >> t;
    int ns = s.length();
    int nt = t.length();
    vector<vector<int>> dp(ns+1, vector<int>(nt+1));
    for(int i=0;i<=ns;i++){
        for(int j=0;j<=nt;j++){
            if(i==0){
                dp[i][j]=j;
                continue;
            }
            else if(j==0){
                dp[i][j] = i;
                continue;
            }
            if(s[i-1]==t[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;
            }
        }
    }
    cout << dp[ns][nt] << endl;
}
