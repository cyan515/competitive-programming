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
  ll a,b,c,d;cin>>a>>b>>c>>d;
  if(a%2==1&&(a+b)%2==1) a--;
  else if(a%2==0&&(a+b)%2==1) a--;
  c -= a;
  d -= b;
  a = 0;
  b = 0;
  if(c<0) {
    c--;c=-c;
  }
  if(d<0) d = -d;
  ll ans = 0;
  ll dy = abs(d - b);
  ll dx = abs(c - a);
  ans += dy;
  if(dx>dy+1) ans += (dx - dy)/2;
  cout << ans << endl;

  return 0;
}
