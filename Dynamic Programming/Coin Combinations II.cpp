#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
int dp[1000007];
int main()
{
    fast
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto& w:a){
        cin >> w;
    }
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=a[i];j<=x;j++){
            dp[j]+=dp[j-a[i]];
            dp[j]%=mod;
        }
    }
    cout << dp[x] << endl;
}