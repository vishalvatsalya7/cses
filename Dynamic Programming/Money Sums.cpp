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
using namespace std;
ll binpow(ll a, ll b, ll m){a %= m;ll res = 1;while (b > 0){if (b & 1) res = res * a % m;a = a * a % m;b >>= 1;}return res;}
/* End of template */

int n, sum;
vector<int> a, ans;
const int mx = 100007;
int dp[mx] = {0};
int main(){
    cin >> n;
    sum = 0;
    a.resize(n);
    for(auto& w:a) cin >>w;
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=mx-1;j>=0;j--){
            if(j>=a[i]){
                dp[j] |= dp[j-a[i]];
            }
        }
    }
    for(int i=1;i<mx;i++){
        if(dp[i]){
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(auto w:ans){
        cout << w << " ";
    }
}

