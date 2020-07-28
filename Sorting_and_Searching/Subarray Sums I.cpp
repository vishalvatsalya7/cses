#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main(){
   // freopen("sm_input.txt", "r" , stdin);
   // freopen("sm_output.txt", "w", stdout);
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for(auto& w:a){
        cin >> w;
    }
    unordered_map<ll,ll> mp;
    ll s=0, ans=0;
    mp[0]=1;
    for(int i=0;i<n;i++){
        s+=a[i];
        if(mp.find(s-x)!=mp.end()){
            ans+=mp[s-x];
        }
        mp[s]++;
    }
    cout << ans << endl;
}


