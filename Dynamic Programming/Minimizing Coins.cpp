#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    fast
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto& w:a){
        cin >> w;
    }
    vector<int> dp(x+1, x+1);
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=a[i];j<=x;j++){
            dp[j] = min(dp[j], 1+dp[j-a[i]]);
        }
    }
    if(dp[x]>=x+1) cout << -1 << endl;
    else
    cout << dp[x] << endl;
}