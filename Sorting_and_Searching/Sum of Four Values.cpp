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
    array<int,4> ans;
    int fl1=0;
    for(int i=0;i<n-3;i++){
        if(a[i].first>x){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        for(int j=i+1;j<n-2;j++){
                for(int k=j+1;k<n-1;k++){
                    if(a[i].first+a[j].first+a[k].first+a[n-1].first<x) continue;
                    int lo = k+1, hi = n-1;
                    int fl=0;
                    while(lo<=hi){
                        int m = lo+(hi-lo)/2;
                        ll sm = a[i].first+a[j].first+a[k].first+a[m].first;
                        if(sm==x){
                            cout << a[i].second+1 << " " << a[j].second+1 << " " << a[k].second+1 << " " << a[m].second+1 << endl;
                            return 0;
                        }
                        else if(sm<x){
                            lo=m+1;
                        }
                        else{
                            hi=m-1;
                        }
                    }
                }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}


