#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
 
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto& w:a) cin >> w;
    ll curr_sum = a[0], mx = a[0];
    for(ll i = 1; i<n;i++){
        curr_sum = max(curr_sum+a[i], a[i]);
        mx = max(mx, curr_sum);
    }
    cout << mx << endl;
}