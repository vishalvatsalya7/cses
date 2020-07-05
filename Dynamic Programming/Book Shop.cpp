#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
int main()
{
    fast
    int n,x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    vector<pair<int,int>> v(n);
    for(auto& w:h){
        cin >> w;
    }
    for(auto& w:s){
        cin >> w;
    }
    for(int i=0;i<n;i++){
        v[i] = make_pair(h[i],s[i]);
    }
    sort(v.begin(), v.end());
    vector<vector<int>> dp(n+1, vector<int>(x+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(i==0||j==0){
                dp[i][j] = 0;
            }
            else if(j-v[i-1].first>=0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i-1].first]+v[i-1].second);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][x] << endl;
}
