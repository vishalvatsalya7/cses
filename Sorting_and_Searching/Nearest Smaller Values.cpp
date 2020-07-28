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
    stack<pair<ll,int>> s;
    vector<int> res(n);
    for(int i=0;i<n;i++){
        if(s.empty()){
            s.push({a[i],i+1});
            res[i]=0;
        }
        else{
            while(!s.empty() && s.top().first>=a[i]){
                s.pop();
            }
            if(s.empty()){
                res[i]=0;
            }
            else{
                res[i]=s.top().second;
            }
            s.push({a[i],i+1});
        }
    }
    for(int i=0;i<n;i++){
        cout << res[i] << " ";
    }
}


