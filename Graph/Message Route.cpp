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
int vis[mx];
vector<int> adj[mx];
int main(){
    int u,v;
    cnt=0;
    vector<int> ans;
    cin >> m >> n;
    for(int i=0;i<n;i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue<int> q;
    q.push(1);
    unordered_map<int,int> mp;
    mp[1]=-1;vis[1]=1;
    while(!q.empty()){
        int sz = q.size();
        for(int t=0;t<sz;t++){
            int x = q.front();q.pop();
            if(x==m){
                cout<<cnt+1<<endl;
                while(1){
                    ans.push_back(x);
                    x=mp[x];
                    if(x==-1) break;
                }
                break;
            }
            for(auto v:adj[x]){
                if(v==x) continue;
                if(!vis[v]){
                    q.push(v);
                    mp[v]=x;
                    vis[v]=1;
                }
            }
        }
        if(ans.size()>0) break;
        cnt++;
    }
    if(ans.size()==0){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        reverse(ans.begin(), ans.end());
        for(auto w: ans){
            cout << w << " ";
        }
    }
}