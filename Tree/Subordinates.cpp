#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
vector<int> adj[200007];
vector<ll> vis;
void dfs(int u){
    vis[u] = 1;
    for(auto v:adj[u]){
        if(vis[v]==0){
            dfs(v);
            vis[u]+=vis[v];
        }
    }
}
int main()
{
    fast
    int n,x;
    cin >> n;
    vis.resize(n+1);
    for(int i=2;i<=n;i++){
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout << (vis[i]-1) << " ";
    }
    cout << endl;
}