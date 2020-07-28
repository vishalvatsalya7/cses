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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto& w:a){
        cin >> w;
    }
    ll lo = *max_element(a.begin(),a.end()), hi = 1e18;
    while(lo<hi){
        ll m = lo+(hi-lo)/2;
        int cnt = 0;
        ll sm =0;
        for(int i=0;i<n;i++){
            if(sm+a[i]>m){
                cnt++;
                sm=0;
            }
            sm+=a[i];
        }
        cnt++;
        if(cnt>k){
            lo = m+1;
        }
        else{
            hi = m;
        }
    }
    cout << lo << endl;
}


