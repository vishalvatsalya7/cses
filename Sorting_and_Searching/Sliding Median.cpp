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
int n, k;
map<ll,ll> m1,m2;
//m1 : max heap
//m2 : min heap
int s1 = 0, s2 = 0;

void balance(){
    ll sz1 = s1;
    ll sz2 = s2;
    if(abs(sz1-sz2)>1){
        if(sz1>sz2){
            ll x = m1.rbegin()->first;
            m1[x]--;
            s1--;
            if(m1[x]==0) m1.erase(x);
            m2[x]++;
            s2++;
        }
        else{
            ll x = m2.begin()->first;
            m2[x]--;
            s2--;
            if(m2[x]==0) m2.erase(x);
            m1[x]++;
            s1++;
        }
    }
}

void add(ll x){
    ll sz1 = s1;
    ll sz2 = s2;
    if(sz1==0 && sz2==0){
        m1[x]++;
        s1++;
    }
    else{
        if(m1.size()>0 && x>m1.rbegin()->first){
            m2[(x)]++;
            s2++;
        }
        else{
            m1[(x)]++;
            s1++;
        }
        balance();
    }
}

void rem(ll x){
    if(m1.size()>0 && m1.count(x)){
        m1[x]--;
        if(m1[x]==0){
            m1.erase(x);
        }
        s1--;
    }
    else{
        m2[x]--;
        if(m2[x]==0){
            m2.erase(x);
        }
        s2--;
    }
    balance();
}
ll getMedian(){
    //balance();
    if(k%2==1){
        ll sz1 = s1;
        ll sz2 = s2;
        //cout << sz1 << "  " << sz2 << endl;
        if(sz1>sz2){
            return (double)(m1.rbegin()->first);
        }
        else{
            return (m2.begin()->first);
        }
    }
    else{
        ll x1 = m1.rbegin()->first;
        ll x2 = m2.begin()->first;
        return min(x1,x2);
    }
}
int main(){
   // freopen("sm_input.txt", "r" , stdin);
   // freopen("sm_output.txt", "w", stdout);
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> ans;
    for(auto& w: a){
        cin >> w;
    }
    for(int i=0;i<k;i++){
        add(a[i]);
    }
    ans.push_back(getMedian());
    //cout << ans.front() << endl;
    for(int i=k;i<n;i++){
        add(a[i]);
        rem(a[i-k]);
        ll as = getMedian();
        ans.push_back(as);
    }
    for(auto w:ans){
        cout << w <<" " ;
    }
    cout << endl;
}

