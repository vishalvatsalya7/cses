#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
bool check(ll m, vector<ll> a, ll t){
    ll ans=0;
    int n = a.size();
    for(int i=0;i<n;i++){
        ans+=m/a[i];
        if(ans>=t) return true;
    }
    return false;
}
 
int main()
{
    fast
    ll n,t;
    cin >> n >> t;
    vector<ll> a(n);
    ll mn = INT_MAX, mx = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    //cout << mx*t << endl;
    ll lo = mn, hi = mx*t;
    while(lo<hi){
        ll m = lo+(hi-lo)/2;
        //cout << m << endl;
        if(check(m,a,t)){
            hi = m;
        }
        else{
            lo = m+1;
        }
    }
    cout << lo << endl;
}