#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
#define vv pair<int,int>
bool cmp(pair<pair<int,int>, int> a1, pair<pair<int,int>, int> a2){
    return (a1.first.first<a2.first.first) || (a1.first.first==a2.first.first && a1.first.second < a2.first.second);
}
class compPr {
    public:
        bool operator() (pair<int,int> a1, pair<int,int> a2) {
            //comparison code here
            return (a1.first>a2.first) || (a1.first==a2.first && a1.second<a2.second);
        }
};
int main()
{
    fast
    int n;
    cin >> n;
    vector<pair<pair<int,int>, int>> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
 
    }
    sort(a.begin(), a.end(), cmp);
    priority_queue<vv, vector<vv>, compPr> pq;
    int room = 1;
    vector<int> ans(n);
    pq.push(make_pair(a[0].first.second, room));
    //cout << room << endl;
    ans[a[0].second] = (room);
    set<int> un;
    un.insert(room);
    for(int i=1;i<n;i++){
        auto x = pq.top();
        int tm = x.first;
        int rm = x.second;
        int idx = a[i].second;
        if(tm<a[i].first.first){
            pq.pop();
            pq.push(make_pair(a[i].first.second, rm));
            ans[idx]=(rm);
            un.insert(rm);
            //cout << rm << endl;
        }
        else{
            pq.push(make_pair(a[i].first.second, un.size()+1));
            ans[idx]=(un.size()+1);
            un.insert(ans[idx]);
            //cout << rm+1 << endl;
        }
    }
    cout << un.size() << endl;
    for(auto w:ans){
        cout << w << " ";
    }
    cout << endl;
}