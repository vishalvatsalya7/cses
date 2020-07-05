#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
const int mx = 2e5+7;
vector<int> adj[mx];
int main()
{
    fast
    int n,q,a,x,k;
    cin >> n >> q;
    for(int i=2;i<=n;i++){
        cin >> a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    int height = 18;
    vector<vector<int>> ancestors(height+1, vector<int>(n+1));
    for(int i=1;i<=n;i++){
        ancestors[0][i] = (i==1)?0:adj[i][0];
    }
    for(int i=1;i<=height;i++){
        for(int j=1;j<=n;j++){
            ancestors[i][j] = ancestors[i-1][ancestors[i-1][j]];
        }
    }
    while(q--){
        cin >> x >> k;
        for(int i=height;i>=0;i--){
            if((1<<i) & k){
                x = ancestors[i][x];
            }
        }
        if(x==0) cout << -1 << endl;
        else
        cout << x << endl;
    }
}