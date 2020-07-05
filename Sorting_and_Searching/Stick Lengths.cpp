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
    sort(a.begin(), a.end());ll ans =0 ;
    for(int i=0;i<n;i++){
        ans+=abs(a[i]-a[n/2]);
    }
    cout << ans << endl;
 
}