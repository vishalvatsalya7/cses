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

int m,n,cnt,l_ele, ele;
const int mx = 1e5+7;
vector<int> adj[mx],ans, vis;
vector<int> mp;
bool dfs(int u, int p){
    vis[u]=1;
    mp[u]=p;
    for(int v:adj[u]){
        if(v==p) continue;
        if(vis[v]){
            l_ele = v;
            ele = u;
            return true;
        }
        if(!vis[v] && dfs(v,u)){
            return true;
        }
    }
    return false;
}
int main(){
    int u,v;
    cnt=0;
    cin >> m >> n;
    mp.resize(m+1,0);
    ele=-1;
    l_ele=-1;
    for(int i=0;i<n;i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vis.resize(m+1,0);
    for(int i=1;i<=m;i++){
        if(!vis[i]){
            bool x = dfs(i,-1);
            if(x){
                ans.push_back(l_ele);
                while(ele!=l_ele){
                    ans.push_back(ele);
                    ele = mp[ele];
                }
                ans.push_back(l_ele);
                cout << ans.size() << endl;
                for(auto w:ans){
                    cout << w <<" " ;
                }
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
