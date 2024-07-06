#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

template <typename Tp>
auto mul_overflow(Tp x, Tp y, Tp& z)
  -> typename std::enable_if<std::is_integral_v<Tp>, bool>::type
{
  using unsigned_type = typename std::make_unsigned<Tp>::type;
  unsigned_type ux = x, uy = y;
  unsigned_type sign_bit = ~(~unsigned_type(0) >> 1);
  if (((ux * uy) & sign_bit) != ((ux & sign_bit) ^ (uy & sign_bit))) return true;
  z = x * y;
  return false;
}

long long powll(long long BASE, long long EXPONENT) {
  long long RET = 1;
  while (EXPONENT > 0) {
    ll res;
    if (EXPONENT & 1) {
      if(mul_overflow(RET,BASE,res)) return -1;
      RET = res;
    }
    if(mul_overflow(BASE,BASE,res)) return -1;
    BASE = res;
    EXPONENT >>= 1;
  }
  return RET;
}

int main() {
  ll n;cin>>n;
  ll ans = 1;
  reps(b,2,30) {
    bool skip = false;
    reps(i,1,b+1) {
      if(i*i==b) {
        skip = true;
      }
    }
    if(skip) continue;
    ll ok = 1;
    ll ng = LINF;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      ll x = powll(mid,b);
      if(x>n || x==-1) ng = mid;
      else ok = mid;
    }
    ans += ok-1;
  }
  cout << ans << endl;

  return 0;
}
