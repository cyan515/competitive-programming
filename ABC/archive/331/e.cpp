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
  ll n,m;cin>>n>>m;
  ll l;cin>>l;
  vector<pair<ll,ll>> a(n);
  vector<pair<ll,ll>> b(m);
  rep(i,n) {
    ll tmp;cin>>tmp;
    a.at(i) = make_pair(tmp,i);
  }
  rep(i,m) {
    ll tmp;cin>>tmp;
    b.at(i) = make_pair(tmp,i);
  }
  set<pair<ll,ll>> cd;
  rep(i,l) {
    ll c,d;cin>>c>>d;c--;d--;
    cd.emplace(c,d);
  }
  sort(all(a));
  sort(all(b));
  reverse(all(a));
  reverse(all(b));
  ll ans = 0;
  priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<>> q;
  rep(j,m) {
    q.emplace(a.at(0).first+b.at(j).first,make_pair(a.at(0).second,b.at(j).second));
  }
  reps(i,1,n) {
    rep(j,m) {
      if(a.at(i).first+b.at(j).first<q.top().first) break;
      q.emplace(a.at(i).first+b.at(j).first,make_pair(a.at(i).second,b.at(j).second));
    }
    while(q.size()>l+2) q.pop();
  }
  while(q.size()) {
    auto [price,pr] = q.top();q.pop();
    if(!cd.count(pr)) ans = max(ans,price);
  }
  cout << ans << endl;

  exit(0);
}
