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
 
int m,n,cnt;
const int mx = 1e5+7;
int vis[mx]={0}, ans[mx]={-1};
vector<int> adj[mx];
bool dfs(int u, int p, int fl){
    vis[u]=1;
    ans[u]=fl;
    for(auto v:adj[u]){
        if(ans[v]==ans[u]) return true;
        if(!vis[v] && dfs(v,u,1-fl)){
            return true;
        }
    }
    return false;
}
 
int main(){
    int u,v;
    cnt=0;
    cin >> m >> n;
    for(int i=0;i<n;i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=1;i<=m;i++) ans[i]=-1;
    for(int i=1;i<=m;i++){
        if(!vis[i]){
            bool x = dfs(i,-1,1);
            if(x){
                cout <<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout << ans[i]+1 << " ";
    }
}