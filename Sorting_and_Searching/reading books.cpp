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
    ll s=0;
    for(auto& w:a){
        cin >> w;
        s+=w;
    }
    sort(a.rbegin(), a.rend());
    cout << max(s, 2*a[0]) << endl;
 
}
