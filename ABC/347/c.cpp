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
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}

int main() {
  ll n,a,b;cin>>n>>a>>b;
  vector<ll> d(n);cin>>d;
  rep(i,n) {
    d.at(i) %= a+b;
  }
  sort(all(d));
  ll ma = 0;
  rep(i,n-1) chmax(ma,d.at(i+1)-d.at(i)-1);
  if(ma>=b || d.back()-d.front()+1<=a) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
