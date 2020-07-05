#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
 
int main()
{
    int n,w,cnt=0;
    cin >> n;
    set<int> s;
    for(ll i = 0; i < n; i++) {
            scanf("%ld", &w);
            if(s.count(w)) continue;
            s.insert(w);
            cnt++;
    }
    printf("%d", cnt);
}