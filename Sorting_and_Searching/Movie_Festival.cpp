#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second<b.second || (a.second==b.second && a.first<b.first);
}
int main()
{
    int n,u,v;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin >> u >> v;
        a[i] = make_pair(u,v);
    }
    sort(a.begin(),a.end(),cmp);
    int last = a[0].second, cnt = 1;
    for(int i=1;i<n;i++){
        if(a[i].first>=last){
            last = a[i].second;
            cnt++;
        }
    }
    cout << cnt << endl;
}