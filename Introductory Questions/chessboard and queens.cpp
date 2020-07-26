#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
string s[8];
bool b[15];
int main(){
    //freopen("fb_input.txt", "r" , stdin);
    //freopen("fb_output.txt", "w", stdout);


    for(int i=0;i<8;i++){
        cin >> s[i];
    }
    int p[8], ans = 0;
    iota(p,p+8,0);
    do{
        bool ok = 1;
        for(int i=0;i<8;i++){
            ok&=s[i][p[i]]=='.';
        }
        memset(b,0,15);
        for(int i=0;i<8;i++){
            if(b[i+p[i]]) ok = 0;
            b[i+p[i]]=1;
        }
        memset(b,0,15);
        for(int i=0;i<8;i++){
            if(b[i+7-p[i]]) ok = 0;
            b[i+7-p[i]]=1;
        }
        ans+=ok;
    }while(next_permutation(p,p+8));
    cout << ans << endl;
}


