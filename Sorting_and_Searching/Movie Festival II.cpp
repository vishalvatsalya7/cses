#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ar array
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vector<ll>, greater<ll>>
using namespace std;
ll binpow(ll a, ll b, ll m){a %= m;ll res = 1;while (b > 0){if (b & 1) res = res * a % m;a = a * a % m;b >>= 1;}return res;}
/* End of template */


const int mx = 2e5+7;
int n,k;
ar<ll,2> a[mx];
int main(){
    //freopen("cs_input.txt", "r" , stdin);
    //freopen("cs_output.txt", "w", stdout);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i][1] >> a[i][0];
    }
    sort(a,a+n);
    int ans = 0;
    multiset<ll> s;
    for(int i=0;i<n;i++){
        auto it = s.lower_bound(a[i][1]+1);
        if(it!=s.begin()){
            --it;
            s.erase(it);
        }
        if(s.size()<k){
            ++ans;
            s.insert(a[i][0]);
        }
    }

    cout << ans << endl;
}
