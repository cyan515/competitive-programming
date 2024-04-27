#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using lll = __int128_t;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
long long ext_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = ext_gcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
int main() {
  ll x,y;cin>>x>>y;
  if(x==0) {
    if(abs(y)==1) {
      cout << 2 << " " << 0 << endl;
    } else if(abs(y)==2) {
      cout << 1 << " " << 0 << endl;
    } else {
      cout << -1 << endl;
    }
    return 0;
  }
  if(y==0) {
    if(abs(x)==1) {
      cout << 0 << " " << 2 << endl;
    } else if(abs(x)==2) {
      cout << 0 << " " << 1 << endl;
    } else {
      cout << -1 << endl;
    }
    return 0;
  }
  ll a,b;
  ll g = ext_gcd(x,-y,a,b);
  if(abs(g)>2) {
    cout << -1 << endl;
    return 0;
  }
  cout << b*2/g << " " << a*2/g << endl;
  
  return 0;
}
