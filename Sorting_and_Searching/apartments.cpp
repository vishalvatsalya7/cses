#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
 
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> cust(n), app(m);
    map<int,int> mp;
    for(auto& w:cust){
        cin >> w;
    }
    for(auto& w:app){
        cin >> w;
        mp[w]++;
    }
    int ans = 0;
    sort(cust.begin(),cust.end());
    for(auto w:cust){
        int lm = max(1,w-k);
        int um = w+k;
        if(mp.size()==0) break;
        auto it1 = mp.lower_bound(lm);
        auto it2 = mp.upper_bound(um);
        if(it1!=mp.end() && (*it1).first>=lm && (*it1).first<=um){
            //cout << (*it1).first << endl;
            mp[(*it1).first]--;
            if(mp[(*it1).first]==0){
                mp.erase((*it1).first);
            }
            ans++;
            continue;
        }
        if(it2==mp.begin()) continue;
        it2--;
        if((*it2).first>=lm && (*it2).first<=um){
            //cout << (*it2).first << endl;
            mp[(*it2).first]--;
            if(mp[(*it2).first]==0){
                mp.erase((*it2).first);
            }
            ans++;
            continue;
        }
    }
    cout << ans << endl;
}