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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n;cin>>n;
  int m;cin>>m;
  // edge, to
  vector g(n,vector<pair<int,int>>());
  vector<tuple<ll,ll,ll,ll>> info(m);
  rep(i,m) {
    ll l,d,k,c,a,b;cin>>l>>d>>k>>c>>a>>b;a--;b--;
    g.at(b).emplace_back(i,a);
    info.at(i) = tuple(l,d,k,c);
  }
  
  priority_queue<pair<ll,int>> q;
  q.emplace(LINF,n-1);
  vector<ll> ans(n,-LINF);
  ans.at(n-1) = LINF;
  while(q.size()) {
    auto [t,v] = q.top();q.pop();
    if(ans.at(v) > t) continue;
    for(auto [ne,nv] : g.at(v)) {
      auto [l,d,k,c] = info.at(ne);
      ll ok = 0;
      ll ng = k;
      while(abs(ok-ng)>1) {
        ll mid = (ok+ng)/2;
        if(l+mid*d+c<=t) ok = mid;
        else ng = mid;
      }
      if(l+ok*d+c>t) continue;
      ll nt = l+ok*d;
      if(ans.at(nv) >= nt) continue;
      ans.at(nv) = nt;
      q.emplace(nt,nv);
    }
  }
  rep(i,n-1) {
    if(ans.at(i)!=-LINF) cout << ans.at(i) << endl;
    else cout << "Unreachable" << endl;
  }

  return 0;
}
