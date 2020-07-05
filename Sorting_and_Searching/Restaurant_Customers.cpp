#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
 
int main()
{
    int n,u,v;
    cin >> n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin >> u >> v;
        mp[u]++;
        mp[v+1]--;
    }
    int sm = 0, mx = INT_MIN;
    for(auto w:mp){
        sm+=w.second;
        mx = max(mx, sm);
    }
    cout << mx << endl;
}