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
  int n;cin>>n;
  vector<int> x(n),y(n);
  rep(i,n) cin>>x.at(i)>>y.at(i);
  long double ans = 0.0;
  long double cx = 0.0;
  long double cy = 0.0;
  auto f = [](long double a,long double b,long double c,long double d) -> long double {
    return hypotl(abs(a-c),abs(b-d));
  };
  rep(i,n) {
    ans += f(cx,cy,x.at(i),y.at(i));
    cx = x.at(i);
    cy = y.at(i);
  }
  ans += f(cx,cy,0.0,0.0);
  cout << fixed << setprecision(20) << ans << endl;

  return 0;
}
