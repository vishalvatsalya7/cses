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

const int mx = 5001;
ll a[mx], dp[mx][mx];
int n;
ll solve(int i, int j){
    if(i<0 || j<0 || i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    ll L = a[i]+min(solve(i+2,j), solve(i+1,j-1));
    ll R = a[j]+min(solve(i+1,j-1), solve(i,j-2));
    dp[i][j] = max(L,R);
    return dp[i][j];
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<mx;i++){
        for(int j=0;j<mx;j++){
            dp[i][j]=-1;
        }
    }
    ll ans = solve(0,n-1);
    cout << ans << endl;
}

