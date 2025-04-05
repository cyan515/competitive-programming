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
  ll n,m;cin>>n>>m;
  ll ans = 0;
  reps(i,0,m+1) {
    ll a = 1;
    rep(_,i) {
      ll b;
      bool ng = __builtin_mul_overflow(a,n,&b);
      if(ng) {
        cout << "inf" << endl;
        return 0;
      }
      a = b;
    }
    ans += a;
    if(ans<0) {
      cout << "inf" << endl;
      return 0;
    }
  }
  if(ans>1000000000) cout << "inf" << endl;
  else cout << ans << endl;

  return 0;
}
