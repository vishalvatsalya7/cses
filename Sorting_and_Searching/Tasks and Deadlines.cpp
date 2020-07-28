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
    //freopen("fb_input.txt", "r" , stdin);
    //freopen("fb_output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<pair<ll,ll>> a(n);
    for(auto& w:a){
        cin >> w.first >> w.second;
    }
    sort(a.begin(), a.end());
    ll ans = 0, t = 0;
    for(int i=0;i<n;i++){
        t=t+a[i].first;
        ans+=a[i].second-t;
    }
    cout << ans << endl;
}


