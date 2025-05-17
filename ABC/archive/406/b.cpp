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
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n;cin>>n;
  ll k;cin>>k;
  ll ans = 1;
  while(n--) {
    ll a;cin>>a;
    ll nx;
    bool ng = __builtin_mul_overflow(ans,a,&nx);
    if(ng) {
      ans = 1;
    } else {
      ans = nx;
      if(to_string(ans).size()>k) ans = 1;
    }
  }
  cout << ans << endl;

  return 0;
}
