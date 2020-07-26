#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
string s;
int n, ans;
bool vis[7][7];

bool ch(int i, int j){
    return i>=0&&i<7&&j>=0&&j<7&&!vis[i][j];
}

//used heuristics from tmwilliam
void dfs(int i, int j, int a=0){
    if(i==6 && j==0){
        if(a==48){
            ans++;
        }
        return;
    }
    vis[i][j]=1;
    if(s[a]=='?' || s[a]=='L'){
        if(j && !vis[i][j-1]){
            if(!(!ch(i,j-2) && ch(i-1,j-1) && ch(i+1,j-1)))
            dfs(i,j-1,a+1);
        }
    }
    if(s[a]=='?' || s[a]=='R'){
        if(j<6 && !vis[i][j+1]){
            if(!(!ch(i,j+2) && ch(i-1,j+1) && ch(i+1,j+1)))
            dfs(i,j+1,a+1);
        }
    }
    if(s[a]=='?' || s[a]=='U'){
        if(i && !vis[i-1][j]){
            if(!(!ch(i-2,j) && ch(i-1,j-1) && ch(i-1,j+1)))
            dfs(i-1,j,a+1);
        }
    }
    if(s[a]=='?' || s[a]=='D'){
        if(i<6 && !vis[i+1][j]){
            if(!(!ch(i+2,j) && ch(i+1,j-1) && ch(i+1,j+1)))
            dfs(i+1,j,a+1);
        }
    }
    vis[i][j]=0;
}
int main(){
    //freopen("fb_input.txt", "r" , stdin);
    //freopen("fb_output.txt", "w", stdout);
    cin >> s;
    n = s.length();
    ans = 0;
    memset(vis,0,sizeof(vis));
    dfs(0,0);
    cout << ans << endl;

}


