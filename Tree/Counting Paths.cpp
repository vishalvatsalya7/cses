#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<int> nodes, depth, index1, ans, lca, mp;
const int mod = 1e9+7;
vector<int> adj[200007];
int n,u,vv,q,cnt;
void dfs(int u, int p, int d){
    nodes[cnt] = u;
    depth[cnt] = d;
    index1[u] = cnt;
    cnt++;
    for(auto v:adj[u]){
        if(v==p) continue;
        dfs(v,u,d+1);
        nodes[cnt] = u;
        depth[cnt] = d;
        index1[u] = cnt;
        cnt++;
    }
}
 
void dfs1(int u, int p){
    int cnt1 = 0;
    for(auto v:adj[u]){
        if(v!=p){
            dfs1(v,u);
            cnt1+=ans[v]-lca[v];
        }
    }
    ans[u] = cnt1-lca[u]+mp[u];
}
int main()
{
    fast
    cnt=0;int a,b;
    cin >> n >> q;
    ans.resize(n+1);
    lca.resize(n+1);
    mp.resize(n+1);
    nodes.resize(2*n-1);
    depth.resize(2*n-1);
    index1.resize(n+1);
    for(int i=0;i<n-1;i++){
        cin >> u >> vv;
        adj[u].push_back(vv);
        adj[vv].push_back(u);
    }
    dfs(1,-1,0);
    //Beginning of Sparse Table
    int nn = 2*n-1;
    vector<int> logp(nn+1);
    logp[1] = 0;
    for(int i=2;i<=nn;i++){
        logp[i] = logp[i/2]+1;
    }
    int k = (int)floor(log2(nn));
    vector<vector<int>> dp(k+1, vector<int>(nn));
    vector<vector<int>> itr(k+1, vector<int>(nn));
    for(int i=0;i<nn;i++){
        dp[0][i] = depth[i];
        itr[0][i] = i;
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j+(1<<i)<nn;j++){
            int first = dp[i-1][j];
            int second = dp[i-1][j+(1<<(i-1))];
            if(first<second){
                dp[i][j] = first;
                itr[i][j] = itr[i-1][j];
            }
            else{
                dp[i][j] = second;
                itr[i][j] = itr[i-1][j+(1<<(i-1))];
            }
        }
    }
    // End of Sparse Table
 
    while(q--){
        cin >> a >> b;
        mp[a]++;
        mp[b]++;
        int l = index1[a];
        int r = index1[b];
        int l1 = min(l,r);
        int r1=max(l,r);
        int len = r1-l1+1;
        int p = logp[len];
        int k1 = (1<<p);
        int left = dp[p][l1];
        int right = dp[p][r1-k1+1];
        if(left<right){
            lca[nodes[itr[p][l1]]]++;
        }
        else{
            lca[nodes[itr[p][r1-k1+1]]]++;
        }
    }
    dfs1(1,-1);
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}