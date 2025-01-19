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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  long double r;cin>>r;
  ll ans = 0;
  long double eps = 1e-12;
  reps(i,1,r) {
    long double dx = 0.5+i;
    long double dy = sqrtl(r*r-dx*dx);
    dy -= 0.5;
    dy += eps;
    if(dy<=0) continue;
    ans += 1;
    ans += 2*(ll)floorl(dy);
  }
  ans *= 2;
  long double dx = 0.5;
  long double dy = sqrtl(r*r-dx*dx);
  dy -= 0.5;
  dy += eps;
  if(dy>0) {
    ans++;
    ans += 2*(ll)floorl(dy);
  }
  cout << ans << endl;

  return 0;
}
