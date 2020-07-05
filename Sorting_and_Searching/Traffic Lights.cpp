#include <bits/stdc++.h>
 
using namespace std;
 
pair<int, int>v[200002];
 
int x, n, ans[200002], v2[200002], nxt[200002], last[200002];
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> x >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i].first;
    v[i].second = i;
    v2[i] = v[i].first;
  }
  v2[n + 1] = x;
  v[n + 1].first = x;
  v[n + 1].second = n + 1;
  sort(v + 1, v + n + 1);
  for (int i = 1; i <= n; i++) {
    nxt[v[i].second] = v[i + 1].second;
    last[v[i].second] = v[i - 1].second;
    ans[n] = max(ans[n], abs(v2[v[i].second] - v2[v[i - 1].second]));
    ans[n] = max(ans[n], abs(v2[v[i].second] - v2[v[i + 1].second]));
  }
  for (int i = n; i > 1; i--) {
    ans[i - 1] = max(ans[i], abs(v2[last[i]] - v2[nxt[i]]));
    nxt[last[i]] = nxt[i];
    last[nxt[i]] = last[i];
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << " ";
  return 0;
}