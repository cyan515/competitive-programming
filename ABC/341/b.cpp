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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n;cin>>n;
  vector<ll> a(n);cin>>a;
  vector<ll> s(n-1),t(n-1);
  rep(i,n-1) cin>>s.at(i)>>t.at(i);
  rep(i,n-1) {
    a.at(i+1) += a.at(i)/s.at(i)*t.at(i);
  }
  cout << a.at(n-1) << endl;

  return 0;
}
