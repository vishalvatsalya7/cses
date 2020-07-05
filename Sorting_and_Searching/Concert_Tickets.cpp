#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
 
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> price(n), cst(m), fl(n);
    map<int,int> mp;
    for(auto& w:price){
        cin >> w;
        mp[w]++;
    }
    for(auto& w:cst){
        cin >> w;
        auto it = mp.upper_bound(w);
        if(it==mp.begin()){
            cout << -1 << endl;
            continue;
        }
        it--;
        if((*it).first<=w){
            mp[(*it).first]--;
            if(mp[(*it).first]==0){
                mp.erase((*it).first);
            }
            cout << (*it).first << endl;
            continue;
        }
        else{
            cout << -1 << endl;
        }
        /*
        if(it==mp.end()) it--;
        if((*it).first<=w){
            mp[(*it).first]--;
            if(mp[(*it).first]==0){
                mp.erase((*it).first);
            }
            cout << (*it).first << endl;
            continue;
        }
        else{
            if(it==mp.begin()){
                cout << -1 << endl;
                continue;
            }
            it--;
            if((*it).first<=w){
                mp[(*it).first]--;
                if(mp[(*it).first]==0){
                    mp.erase((*it).first);
                }
                cout << (*it).first << endl;
                continue;
            }
            else{
                cout<<-1<<endl;
            }
        }
        */
    }
}