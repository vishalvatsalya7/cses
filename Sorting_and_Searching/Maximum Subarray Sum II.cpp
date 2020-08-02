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

const int mx = 2e5+7;
int n,a,b;
vll pre;
ll v;
int main(){
    cin >> n >> a >> b;
    pre.resize(n+1);
    for(int i=0;i<n;i++){
        cin >> pre[i+1];
        pre[i+1] += pre[i];
    }
    ll ans = -1e18;
    map<ll,ll> s;
    for(int i=0;i<=n;i++){
        if(i>=a){
            s[(pre[i-a])]++;
        }
        if(s.size()){
            ans = max(ans, pre[i]-((s.begin())->first));
        }
        if(i>=b){
            s[(pre[i-b])]--;
            if(s[pre[i-b]]==0) s.erase(pre[i-b]);
        }
    }
    cout << ans << endl;
}

/*
8 1 2
-1 3 -2 5 3 -5 2 2
*/
