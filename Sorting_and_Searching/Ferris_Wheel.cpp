#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
int main()
{
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto& w:a){
        cin >> w;
    }
    sort(a.begin(), a.end());
    int cnt=0;
    int i = 0, j = n-1;
    while(i<=j){
        if(a[i]+a[j]<=x){
            i++;j--;
            cnt++;
        }
        else{
            j--;
            cnt++;
        }
    }
    cout << cnt << endl;
}