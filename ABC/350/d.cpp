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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  ll n,m;cin>>n>>m;
  vector<ll> a(m),b(m);
  rep(i,m) cin>>a.at(i)>>b.at(i);
  dsu uf(n);
  vector<ll> deg(n,0);
  rep(i,m) {
    a.at(i)--;b.at(i)--;
    uf.merge(a.at(i),b.at(i));
    deg.at(a.at(i))++;
    deg.at(b.at(i))++;
  }
  ll ans = 0;
  for(auto v : uf.groups()) {
    ll cnt = v.size()*(v.size()-1)/2;
    ll ds = 0;
    for(auto ele : v) {
      ds += deg.at(ele);
    }
    ds /= 2;
    cnt -= ds;
    ans += cnt;
  }
  cout << ans << endl;

  return 0;
}
