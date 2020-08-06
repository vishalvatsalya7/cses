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
#define mod 1000000007
using namespace std;
ll binpow(ll a, ll b, ll m){a %= m;ll res = 1;while (b > 0){if (b & 1) res = res * a % m;a = a * a % m;b >>= 1;}return res;}
/* End of template */
// copied from william lin's solution
const int mx = 2e5+7;
int n;
ar<ll,3> a[mx];
int main(){
    cin >> n;
    //a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i][1] >> a[i][0] >> a[i][2];
    }
    sort(a,a+n);
    set<ar<ll,2>> dp;
    dp.insert({0,0});
    ll ans=0;
    for(int i=0;i<n;i++){
        auto it = dp.lower_bound({a[i][1]});
        --it;
        ans = max(ans, a[i][2]+(*it)[1]);
        //s.insert({a[i].first, ans});
        dp.insert({a[i][0],ans});
    }
    cout << ans << endl;
}

