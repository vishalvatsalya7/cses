#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
vector<int> adj[200007];
vector<int> in, out;
void dfs1(int u, int p){
    for(auto v:adj[u]){
        if(v!=p){
            dfs1(v,u);
            in[u] = max(in[u], 1+in[v]);
        }
    }
}
 
void dfs2(int u, int p){
    int mx1 = -1, mx2 = -1;
    for(auto v:adj[u]){
        if(v==p) continue;
        if(in[v]>=mx1){
            mx2=mx1;
            mx1=in[v];
        }
        else if(in[v]>mx2){
            mx2=in[v];
        }
    }
    for(auto v:adj[u]){
        if(v==p) continue;
        int largest = mx1;
        if(mx1==in[v]){
            largest = mx2;
        }
        out[v] = 1+max(out[u], 1+largest);
        dfs2(v,u);
    }
}
int main()
{
    fast
    int n,u,v;
    cin >> n;
    in.resize(n+1);
    out.resize(n+1);
    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    for(int i=1;i<=n;i++){
        cout << max(in[i],out[i]) << " " ;
    }
    cout << endl;
}