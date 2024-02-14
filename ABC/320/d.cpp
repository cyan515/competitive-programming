#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n;cin>>n;
  ll m;cin>>m;
  vector p(n,vector<pair<ll,pair<ll,ll>>>());
  map<ll,pair<ll,ll>> ans;
  ans[0] = make_pair(0,0);
  dsu D(n);
  rep(i,m) {
    ll a,b,x,y;cin>>a>>b>>x>>y;a--;b--;
    p.at(a).push_back(make_pair(b,make_pair(x,y)));
    p.at(b).push_back(make_pair(a,make_pair(-x,-y)));
  }
  queue<ll> q;
  q.push(0);
  while(q.size()) {
    ll v = q.front();q.pop();
    auto [x,y] = ans[v];
    for(auto ele : p.at(v)) {
      ll nx = ele.first;
      if(ans.find(nx)!=ans.end()) continue;
      ll dx = ele.second.first;
      ll dy = ele.second.second;
      ans[nx] = make_pair(x+dx,y+dy);
      q.push(nx);
    }
  }
  rep(i,n) {
    if(ans.find(i)==ans.end()) cout << "undecidable" << endl;
    else cout << ans[i].first << " " << ans[i].second << endl;
  }

  exit(0);
}
