#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ar array
#define ff first
#define vi vector<int>
#define vll vector<ll>
#define ss second
#define all(x) x.begin(),x.end()
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vector<ll>, greater<ll>>
#define mod 1000000007
using namespace std;
ll binpow(ll a, ll b, ll m){a %= m;ll res = 1;while (b > 0){if (b & 1) res = res * a % m;a = a * a % m;b >>= 1;}return res;}
/* End of template */

int m,n,ans;
const int mx = 1007;
string a[mx];
int vis[mx][mx];
int dx[4] = {-1,0,1,0}; //U,R,D,L
int dy[4] = {0,1,0,-1};
int main(){
    cin >> m >> n;
    int x=0,y=0;
    for(int i=0;i<m;i++){
        cin >> a[i];
        for(int j=0;j<n;j++){
            if(a[i][j]=='A'){
                x=i;y=j;
            }
        }
    }
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y]=1;
    int ans = 0;
    //vector<char> ans;
    unordered_map<int,char> dir;
    dir[0]='U';dir[1]='R';dir[2]='D';dir[3]='L';
    unordered_map<int, pair<int,char>> mp;
    mp[x*n+y] = {-1,'?'};
    string ans1 = "";
    while(!q.empty()){
        int sz = q.size();
        for(int k=0;k<sz;k++){
            auto w = q.front();q.pop();
            x = w.first;
            y = w.second;
            if(a[x][y]=='B') {
                cout << "YES" << endl;
                cout << ans << endl;
                while(1){
                    ans1.push_back(mp[x*n+y].second);
                    int z = mp[x*n+y].first;
                    if(z==-1) break;
                    x = (z)/n;
                    y = (z)%n;
                }
                break;
            }
            for(int i=0;i<4;i++){
                int xx = x+dx[i];
                int yy = y+dy[i];
                if(xx<0||yy<0||xx>=m||yy>=n||vis[xx][yy]||a[xx][yy]=='#') continue;
                q.push({xx,yy});
                mp[xx*n+yy] = {x*n+y, dir[i]};
                vis[xx][yy]=1;
            }
        }
        if(ans1.size()>0) break;
        ans++;
    }
    if(ans1.size()==0)
    cout << "NO" << endl;
    else{
        ans1.pop_back();
        reverse(ans1.begin(),ans1.end());
        cout << ans1 << endl;
    }
}

