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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  ll n,x,y;cin>>n>>x>>y;
  vector<pair<ll,ll>> ab(n);
  ll ans = n;
  rep(i,n) cin>>ab.at(i).first;
  rep(i,n) cin>>ab.at(i).second;
  auto f = [](pair<ll,ll> x,pair<ll,ll> y) -> bool {
    if(x.first!=y.first) return x.first > y.first;
    else return x.second > y.second;
  };
  sort(all(ab), f);
  ll s = 0;
  ll t = 0;
  rep(i,n) {
    s += ab.at(i).first;
    t += ab.at(i).second;
    if(s>x || t>y) {
      ans = min(ans,i+1);
      break;
    }
  }
  s = 0;
  t = 0;
  rep(i,n) swap(ab.at(i).first,ab.at(i).second);
  sort(all(ab), f);
  rep(i,n) {
    t += ab.at(i).first;
    s += ab.at(i).second;
    if(s>x || t>y) {
      ans = min(ans,i+1);
      break;
    }
  }
  cout << ans << endl;

  return 0;
}
