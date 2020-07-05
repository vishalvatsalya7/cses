#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
int main()
{
    fast
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& w:a) cin >> w;
    map<int,int> mp;
    for(auto w:a){
        if(mp.size()==0){
            mp[w]++;
        }
        else{
            auto it = mp.upper_bound(w);
            if(it==mp.end()){
                mp[w]++;
            }
            else{
                int x = (*it).first;
                mp[x]--;
                if(mp[x]==0) mp.erase(x);
                mp[w]++;
            }
        }
    }
    int ans = 0;
    for(auto w:mp) ans+=w.second;
    cout << ans << endl;
}