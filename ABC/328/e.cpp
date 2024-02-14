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
  ll n,m,k;cin>>n>>m>>k;
  vector<tuple<int,int,ll>> es;
  rep(i,m) {
    ll u,v,w;cin>>u>>v>>w;u--;v--;
    es.emplace_back(u,v,w);
  }
  vector<bool> choose(m,false);
  rep(i,n-1) {
    choose.at(i) = true;
  }
  sort(all(choose));
  ll ans = k;
  do {
    dsu uf(n);
    rep(i,m) {
      if(choose.at(i)) uf.merge(get<0>(es.at(i)),get<1>(es.at(i)));
    }
    if(uf.size(0)!=n) continue;
    ll cnt = 0;
    rep(i,m) if(choose.at(i)) cnt += get<2>(es.at(i));
    ans = min(ans,cnt%k);
  } while(next_permutation(all(choose)));
  cout << ans << endl;

  exit(0);
}
