#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  int n,m;cin>>n>>m;
  vector g(n,vector<int>(0));
  rep(i,n-1) {
    int p;cin>>p;p--;
    g.at(p).push_back(i+1);
  }
  map<int,int> mp;
  rep(i,n) mp[i] = -1;
  rep(i,m) {
    int x,y;cin>>x>>y;x--;
    mp[x] = max(mp[x],y);
  }
  queue<pair<int,int>> q;
  q.push(make_pair(0,mp[0]));
  int ans = 0;
  while(q.size()) {
    int v = q.front().first;
    int h = q.front().second;
    if(h>=0) ans++;
    q.pop();
    for(int ele : g.at(v)) {
      q.push(make_pair(ele,max(h-1,mp[ele])));
    }
  }
  cout << ans << endl;

  exit(0);
}
