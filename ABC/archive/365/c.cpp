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
  ll n,m;cin>>n>>m;
  vector<ll> a(n);cin>>a;
  ll ok = 0;
  ll ng = LINF+1;
  while(abs(ok-ng)>1) {
    ll mid = (ok+ng) / 2;
    ll sum = 0;
    rep(i,n) sum += min(a.at(i),mid);
    if(sum>m) ng = mid;
    else ok = mid;
  }
  if(ok==LINF) cout << "infinite " << endl;
  else cout << ok << endl;

  return 0;
}
