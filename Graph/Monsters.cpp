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

const int mx = 1007;
int m,n,si,sj;
string a[mx];
int d1[mx][mx], d2[mx][mx], vis[mx][mx],p1[mx][mx], p2[mx][mx];
vector<pair<int,int>> v;
void bfs(vector<pair<int,int>> nodes, int d[mx][mx], int p[mx][mx]){
    queue<pair<int,int>> q;
    memset(vis, 0, sizeof(vis));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            d[i][j] = INT_MAX;
        }
    }
    for(auto w:nodes){
        q.push(w);
        vis[w.first][w.second]=1;
        d[w.first][w.second]=1;
    }

    while(!q.empty()){

        auto ww = q.front();q.pop();
        int x = ww.first;
        int y = ww.second;
        for(int i=0;i<4;i++){
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(xx<0||yy<0||xx>=m||yy>=n||vis[xx][yy]==1||a[xx][yy]=='#') continue;
            vis[xx][yy]=1;
            d[xx][yy] = d[x][y]+1;
            p[xx][yy] = i; // storing the parent direction for backtracking
            q.push({xx,yy});
        }
    }

}

int main(){
    cin >> m >> n;
    for(int i=0;i<m;i++){
        cin >> a[i];
        for(int j=0;j<n;j++){
            if(a[i][j]=='A'){
                si = i;
                sj = j;
                a[i][j]='.';
            }
            if(a[i][j]=='M'){
                v.push_back({i,j});
                a[i][j]='.';
            }
        }
    }

    if(si==0 || si==m-1 || sj==0 || sj==n-1){
        cout << "YES" << endl;
        cout << 0 << endl;
        return 0;
    }

    bfs({{si,sj}}, d1, p1);
    bfs(v,d2,p2);
    int ti=-1,tj=-1;
    string ans = "";

    for(int i=0;i<n;i++){
        if(d1[0][i]<d2[0][i]) ti=0,tj=i;
        if(d1[m-1][i]<d2[m-1][i]) ti = m-1, tj = i;
    }

    for(int i=0;i<m;i++){
        if(d1[i][0]<d2[i][0]) ti = i, tj = 0;
        if(d1[i][n-1]<d2[i][n-1]) ti = i, tj = n-1;
    }

    if(ti==-1){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
   // cout << ti << " " << tj << endl;
    while(ti^si || tj^sj){
        ans+=dir[p1[ti][tj]];
        int dd = p1[ti][tj]^2; // for reversing the direction 
        ti += dx[dd];
        tj += dy[dd];
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
