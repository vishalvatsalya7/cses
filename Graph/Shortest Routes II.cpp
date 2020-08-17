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
#define INF 1e18+7
#define all(x) x.begin(),x.end()
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vector<ll>, greater<ll>>
#define mod 1000000007
using namespace std;
int dx[4] = {-1,0,1,0}; //U,R,D,L
int dy[4] = {0,1,0,-1};
char dir[4] = {'U','R','D','L'};
ll binpow(ll a, ll b, ll m){a %= m;ll res = 1;while (b > 0){if (b & 1) res = res * a % m;a = a * a % m;b >>= 1;}return res;}
/* End of template */

const int mx = 507;
int m,n,q;
ll a,b;
ll c;
vector<pair<ll,ll>> adj[mx];
ll dist[mx][mx];
int main(){
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                dist[i][j]=0;
            }
            else{
                if(dist[i][j]==0) dist[i][j]=INF;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    while(q--){
        cin >> a >> b;
        if(dist[a][b]==INF)
        cout << -1 << endl;
        else cout << dist[a][b] << endl;
    }
}
