#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ar array
#define ff first
#define vi vector<int>
#define vll vector<ll>
#define ss second
#define all(x) x.begin(),x.end()
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vector<ll>, greater<ll>>
using namespace std;
ll binpow(ll a, ll b, ll m){a %= m;ll res = 1;while (b > 0){if (b & 1) res = res * a % m;a = a * a % m;b >>= 1;}return res;}
/* End of template */

ll dp[507][507];

int main(){
    int a, b;
    cin >> a >> b;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i!=j) dp[i][j]=1e18;
            for(int k=1;k<i;k++){
                dp[i][j]=min(dp[i][j], 1+dp[k][j]+dp[i-k][j]);
            }
            for(int k=1;k<j;k++){
                dp[i][j]=min(dp[i][j], 1+dp[i][k]+dp[i][j-k]);
            }
        }
    }
    cout << dp[a][b] << endl;
}

