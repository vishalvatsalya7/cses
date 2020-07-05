#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
vector<int> adj[200007];
int id, mx;
void dfs(int u, int p, int dist){
    if(mx<dist){
        id = u;
        mx = dist;
        //cout << id << " " << mx << endl;
    }
    for(auto v:adj[u]){
        if(v==p) continue;
        dfs(v, u, dist+1);
    }
}
int main()
{
    fast
    int n,u,v;
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    mx = 0;
    dfs(1,-1,0);
    dfs(id,-1,0);
    cout << mx << endl;
}