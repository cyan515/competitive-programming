#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n;cin>>n;
  ll a,b,c;cin>>a>>b>>c;
  vector d(n,vector<ll>(n));
  rep(i,n) rep(j,n) cin>>d.at(i).at(j);
  vector g(2*n,vector<pair<ll,int>>());
  rep(i,n) rep(j,n) {
    g.at(i).emplace_back(d.at(i).at(j)*a,j);
    g.at(i).emplace_back(d.at(i).at(j)*b+c,j+n);
    g.at(i+n).emplace_back(d.at(i).at(j)*b+c,j+n);
  }
  priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
  q.emplace(0,0);
  vector<ll> dist(2*n,LINF);
  dist.at(0) = 0;
  while(q.size()) {
    auto [d,v] = q.top();q.pop();
    if(dist.at(v) < d) continue;
    for(auto [w,nv] : g.at(v)) {
      if(dist.at(nv)<=dist.at(v)+w) continue;
      dist.at(nv) = dist.at(v) + w;
      q.emplace(dist.at(v)+w,nv);
    }
  }
  cout << min(dist.at(n-1),dist.at(2*n-1)) << endl;

  exit(0);
}
