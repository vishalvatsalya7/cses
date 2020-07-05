#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
int main()
{
    int n,x,a;
    cin >> n >> x;
    map<int,int> mp;
    vector<int> v(n);
    for(auto& w:v) cin >> w;
    for(int i=0;i<n;i++){
        a = v[i];
        if(mp.count(x-a)){
            cout << mp[x-a]+1 << " " << i+1 << endl;
            return 0;
        }
        else{
            mp[a]=i;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}