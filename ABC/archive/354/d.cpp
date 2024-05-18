#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
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
void YN(bool b){cout<<(b?"Yes":"No")<<endl;}

int main() {
  ll a,b,c,d;cin>>a>>b>>c>>d;
  a += 4*1000000000LL;
  b += 4*1000000000LL;
  c += 4*1000000000LL;
  d += 4*1000000000LL;
  d -= b;d+=b%2;b%=2;
  c -= a;c+=a%4;a%=4;
  auto area = [](ll x,ll y) -> ll {
    if(y%2==0) {
      if(x%4==0) {
        return x*y;
      }
      if(x%4==1) {
        ll ret = 0;
        ret = (x/4)*(y/2)*8;
        ret += y/2*3;
        return ret;
      }
      if(x%4==2) {
        ll ret = 0;
        ret = (x/4)*(y/2)*8;
        ret += y*3;
        return ret;
      }
      if(x%4==3) {
        ll ret = 0;
        ret = (x/4)*(y/2)*8;
        ret += y/2*7;
        return ret;
      }
    } else {
      if(x%4==0) {
        ll ret = 0;
        ret = (x/4)*(y/2)*8;
        ret += x;
        return ret;
      }
      if(x%4==1) {
        ll ret = 0;
        ret = (x/4)*(y/2)*8;
        ret += y/2*3;
        ret += x/4*4;
        ret += 2;
        return ret;
      }
      if(x%4==2) {
        ll ret = 0;
        ret = (x/4)*(y/2)*8;
        ret += y/2*6;
        ret += x/4*4;
        ret += 3;
        return ret;
      }
      if(x%4==3) {
        ll ret = 0;
        ret = (x/4)*(y/2)*8;
        ret += y/2*7;
        ret += x/4*4;
        ret += 3;
        return ret;
      }
    }
  };
  // cout << area(c,d) << endl;
  // cout << area(c,b) << endl;
  // cout << area(a,d) << endl;
  // cout << area(a,b) << endl;
  assert(area(0,0) == 1);
  ll ans = area(c,d) - area(c,b) - area(a,d) + area(a,b);
  cout << ans << endl;

  return 0;
}
