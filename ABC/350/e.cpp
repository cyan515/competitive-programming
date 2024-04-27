#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  cout << fixed << setprecision(20);
  ll n,a,x,y;cin>>n>>a>>x>>y;
  map<ll,long double> memo;
  auto f = [&](auto f,ll v) -> long double {
    if(v==0) return 0.0;
    if(memo.find(v)!=memo.end()) return memo.at(v);
    long double ret = LINF;
    chmin(ret,f(f,v/a)+(long double)x);
    long double ex = 0.0;
    reps(i,2,7) {
      ex += f(f,v/i)+((long double)y)*6.0/5.0;
    }
    ex /= 5;
    chmin(ret,ex);
    return memo[v] = ret;
  };
  long double ans = f(f,n);
  cout << ans << endl;

  return 0;
}
