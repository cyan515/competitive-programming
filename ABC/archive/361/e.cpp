#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  ll n;cin>>n;
  vector g(n,vector<pair<ll,ll>>());
  rep(i,n-1) {
    int a,b,c;cin>>a>>b>>c;a--;b--;
    g.at(a).push_back(pair(c,b));
    g.at(b).push_back(pair(c,a));
  }
  ll ans = 0;
  rep(i,n) rep(j,g.at(i).size()) {
    ans += g.at(i).at(j).first;
  }
  auto f = [&](int s) -> pair<int,ll> {
    queue<int> q;
    q.push(s);
    vector<bool> seen(n,false);
    seen.at(s) = true;
    vector<ll> dist(n,LINF);
    dist.at(s) = 0;
    while(q.size()) {
      int v = q.front();q.pop();
      for(auto [c,nv] : g.at(v)) {
        if(seen.at(nv)) continue;
        seen.at(nv) = true;
        q.push(nv);
        dist.at(nv) = dist.at(v) + c;
      }
    }
    ll ma = -LINF;
    int idx = -1;
    rep(i,n) {
      if(chmax(ma,dist.at(i))) idx = i;
    }
    return pair(idx,ma);
  };
  ll x = f(f(0).first).second;
  ans -= x;
  cout << ans << endl;

  return 0;
}
