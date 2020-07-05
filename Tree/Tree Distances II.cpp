#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
vector<int> adj[200007];
vector<ll> in, out, sz;
int n,u,v;
void dfs1(int u, int p){
    sz[u]=1;
    for(auto v:adj[u]){
        if(v==p) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        in[u]+=in[v]+sz[v];
    }
}
 
void dfs2(int u, int p){
    for(auto v:adj[u]){
        if(v==p) continue;
        out[v] = out[u]+in[u]-in[v]+n-2*sz[v];
        dfs2(v,u);
    }
}
int main()
{
    fast
    cin >> n;
    in.resize(n+1);
    out.resize(n+1);
    sz.resize(n+1);
    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    for(int i=1;i<=n;i++){
        cout << (in[i]+out[i]) << " " ;
    }
    cout << endl;
}