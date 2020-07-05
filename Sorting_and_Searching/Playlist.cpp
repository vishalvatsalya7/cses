#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& w:a){
        cin >> w;
    }
    map<int,int> mp;
    int j = 0, len = 0;
    for(int i=0;i<n;i++){
        if(mp.count(a[i])){
            j = max(mp[a[i]]+1, j);
        }
        len = max(len, i-j+1);
        mp[a[i]]=i;
    }
    cout << len << endl;
}