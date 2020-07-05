#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
int dp[100007][111];
int solve(int idx, vector<int>& a, int m, int last_char){
    if(idx>=a.size()){
        return 1;
    }
    if(idx>0 && a[idx]!=0 && abs(a[idx]-a[idx-1])>1) return 0;
    if(dp[idx][last_char]!=-1) return dp[idx][last_char];
    int ans = 0;
    if(a[idx]==0){
        if(idx>0){
            for(int i = max(1, a[idx-1]-1); i<=min(m, a[idx-1]+1);i++){
                a[idx] = i;
                ans+=solve(idx+1,a,m,i);
                ans%=mod;
                a[idx] = 0;
            }
        }
        else{
            for(int i = 1; i<=m;i++){
                a[idx] = i;
                //cout << i << endl;
                ans+=solve(idx+1,a,m,i);
                ans%=mod;
                a[idx] = 0;
            }
        }
    }
    else{
        //cout<<"j"<<endl;
        ans += solve(idx+1,a,m,a[idx]);
        ans %= mod;
    }
    dp[idx][last_char] = ans;
    return ans;
}
int main()
{
    fast
    int n,m,i;
    i=0;
    cin >> n >> m;
    vector<int> a(n), un;
    for(auto& w:a){
        cin >> w;
        //dp[i++] = -1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=-1;
        }
    }
    int ans = solve(0, a, m,0);
    cout << ans << endl;
}