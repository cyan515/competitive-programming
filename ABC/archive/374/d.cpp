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
  ll n,ss,tt;cin>>n>>ss>>tt;
  long double s = ss;
  long double t = tt;
  vector<long double> a(n),b(n),c(n),d(n);
  rep(i,n) cin>>a.at(i)>>b.at(i)>>c.at(i)>>d.at(i);
  vector<int> v(n);
  rep(i,n) v.at(i) = i;
  long double ans = LINF;
  auto dist = [](long double w,long double x,long double y,long double z) -> long double {
    return sqrtl(abs(w-y)*abs(w-y)+abs(x-z)*abs(x-z));
  };
  do {
    rep(bit,1<<n) {
      long double cx = 0;
      long double cy = 0;
      long double sum = 0;
      rep(i,n) {
        int ii = v.at(i);
        sum += dist(a.at(ii),b.at(ii),c.at(ii),d.at(ii))/t;
        if((bit&(1<<i))==0) {
          sum += dist(cx,cy,a.at(ii),b.at(ii))/s;
          cx = c.at(ii);
          cy = d.at(ii);
        } else {
          sum += dist(cx,cy,c.at(ii),d.at(ii))/s;
          cx = a.at(ii);
          cy = b.at(ii);
        }
      }
      chmin(ans,sum);
    }
  } while(next_permutation(all(v)));
  cout << fixed << setprecision(20);
  cout << ans << endl;

  return 0;
}
