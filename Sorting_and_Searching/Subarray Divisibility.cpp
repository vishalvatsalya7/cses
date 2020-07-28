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
    cin >> n;
    vector<ll> a(n);
    for(auto& w:a){
        cin >> w;
    }
    map<ll,ll> mp;
    ll ans =0, s=0 ;
    mp[0]=1;
    for(int i=0;i<n;i++){
        s=(s+a[i]%n+n)%n;
        if(mp.find(s)!=mp.end()){
            ans+=mp[s];
        }
        mp[s]++;
    }
    cout << ans << endl;
}


