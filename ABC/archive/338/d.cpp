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
  vector<ll> x(m);cin>>x;
  rep(i,m) x.at(i)--;
  vector<ll> imos(n,0);
  ll base = 0;
  rep(i,m-1) {
    ll d = abs(x.at(i)-x.at(i+1));
    ll l = min(x.at(i),x.at(i+1));
    ll r = max(x.at(i),x.at(i+1));
    if(d<=n/2) {
      base += d;
      imos.at(l) += n-d*2;
      imos.at(r) -= n-d*2;
    } else {
      base += n-d;
      imos.at(r) += 2*d-n;
      imos.at(0) += 2*d-n;
      imos.at(l) -= 2*d-n;
    }
  }
  rep(i,n-1) imos.at(i+1) += imos.at(i);
  ll mi = LINF;
  rep(i,n) mi = min(mi,imos.at(i));
  cout << mi+base << endl;

  exit(0);
}
