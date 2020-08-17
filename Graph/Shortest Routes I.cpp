#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ar array
#define ff first
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define ss second
#define INF 1e18+7
#define all(x) x.begin(),x.end()
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vector<ll>, greater<ll>>
#define mod 1000000007
using namespace std;
int dx[4] = {-1,0,1,0}; //U,R,D,L
int dy[4] = {0,1,0,-1};
char dir[4] = {'U','R','D','L'};
ll binpow(ll a, ll b, ll m){a %= m;ll res = 1;while (b > 0){if (b & 1) res = res * a % m;a = a * a % m;b >>= 1;}return res;}
/* End of template */

const int mx = 1e5+7;
int m,n;
ll a,b;
ll c;
vector<pair<ll,ll>> adj[mx];
vector<ll> dist;
int main(){
    cin >> m >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        adj[a].pb({b,c});
    }
    dist.resize(m+1,INF);
    dist[1]=0;
    priority_queue<pair<ll,ll>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto x = pq.top();pq.pop();
        ll u = x.second;
        if(-1*x.first>dist[u]) continue; //to stop from TLE
        for(auto w:adj[u]){
            ll v = w.first;
            ll wt_v = w.second;
            if(dist[v]>dist[u]+wt_v){
                dist[v] = dist[u]+wt_v;
                pq.push({-dist[v], v});
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout << dist[i] << " ";
    }
}
