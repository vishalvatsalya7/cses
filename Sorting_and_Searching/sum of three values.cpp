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
    int n;ll x;
    cin >> n >> x;
    vector<pair<ll,int>> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    array<int,3> ans;
    int fl1=0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            int lo = j+1, hi = n-1;
            int fl=0;
            while(lo<=hi){
                int m = lo+(hi-lo)/2;
                ll sm = a[i].first+a[j].first+a[m].first;
                if(sm==x){
                    //cout << sm << endl;
                    ans[0]=a[i].second+1;
                    ans[1]=a[j].second+1;
                    ans[2]=a[m].second+1;
                    fl=1;
                    break;
                }
                else if(sm<x){
                    lo=m+1;
                }
                else{
                    hi=m-1;
                }
            }
            if(fl){
                fl1=1;
                break;
            }
        }
        if(fl1) break;
    }
    if(fl1==0){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    }
}


