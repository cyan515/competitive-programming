#include <bits/stdc++.h>
#include <atcoder/math>
using namespace atcoder;
// using mint = modint1000000007;
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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

// https://atcoder.jp/contests/abc022/tasks/abc022_d
int main() {
  ll n;cin>>n;
  vector<ll> x(n),y(n),xx(n),yy(n);
  rep(i,n) cin>>x.at(i)>>y.at(i);
  rep(i,n) cin>>xx.at(i)>>yy.at(i);
  auto f = [&](vector<ll>& vec) -> long double {
    long double sum = 0;
    for(auto ele : vec) sum += ele;
    return sum/n;
  };
  auto gx1 = f(x);
  auto gy1 = f(y);
  auto gx2 = f(xx);
  auto gy2 = f(yy);
  long double d1 = 0;
  long double d2 = 0;
  rep(i,n) {
    chmax(d1,hypotl(x.at(i)-gx1,y.at(i)-gy1));
  }
  rep(i,n) {
    chmax(d2,hypotl(xx.at(i)-gx2,yy.at(i)-gy2));
  }
  cout << fixed << setprecision(20) << d2/d1 << endl;
  
  return 0;
}
