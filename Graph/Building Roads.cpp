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
#define all(x) x.begin(),x.end()
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vector<ll>, greater<ll>>
#define mod 1000000007
using namespace std;
int dx[4] = {-1,0,1,0}; //U,R,D,L
int dy[4] = {0,1,0,-1};
ll binpow(ll a, ll b, ll m){a %= m;ll res = 1;while (b > 0){if (b & 1) res = res * a % m;a = a * a % m;b >>= 1;}return res;}
/* End of template */
 
int m,n,ans;
const int mx = 1e5+7;
int vis[mx];
vector<int> adj[mx];
void dfs(int u, int par){
    vis[u]=1;
    for(auto v:adj[u]){
        if(v==par) continue;
        if(!vis[v]){
            dfs(v,u);
        }
    }
}
int main(){
    int u,v;
    ans = 0;
    vector<int> z;
    cin >> m >> n;
    for(int i=0;i<n;i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=1;i<=m;i++){
        if(!vis[i]){
            dfs(i,-1);
            ans++;
            z.pb(i);
        }
    }
    cout << ans-1 << endl;
    z.resize(ans);
    for(int i=0;i<ans-1;i++){
        cout << z[i] << " " << z[i+1] << endl;
    }
}