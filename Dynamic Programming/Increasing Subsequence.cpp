#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ar array
#define ff first
#define vi vector<int>
#define vll vector<ll>
#define ss second
#define all(x) x.begin(),x.end()
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vector<ll>, greater<ll>>
#define mod 1000000007
using namespace std;
ll binpow(ll a, ll b, ll m){a %= m;ll res = 1;while (b > 0){if (b & 1) res = res * a % m;a = a * a % m;b >>= 1;}return res;}
/* End of template */

const int mx = 2e5+7;
int n;
int a[mx];
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    multiset<int> m;
    multiset<int>::iterator it;
    for(int i=0;i<n;i++){
        m.insert(a[i]);
        it = m.lower_bound(a[i]);
        it++;
        if(it!=m.end()){
            m.erase(it);
        }
    }
    cout << m.size() << endl;
}

