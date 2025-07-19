#include <bits/stdc++.h>
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
  ll n,m;cin>>n>>m;
  vector<ll> a(m),b(m);
  rep(i,m) cin>>a.at(i)>>b.at(i);
  vector<int> ord(m);
  rep(i,m) ord.at(i) = i;
  sort(all(ord),[&](int i,int j) -> bool {
    return a.at(i)-b.at(i)<a.at(j)-b.at(j);
  });
  ll ans = 0;
  for(auto i : ord) {
    ll ok = 0;
    ll ng = LINF;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      ll cnt;
      bool of = __builtin_mul_overflow(a.at(i)-b.at(i),mid-1,&cnt);
      if(of) {
        ng = mid;
        continue;
      }
      ll x = n - cnt - a.at(i);
      if(x>=0) ok = mid;
      else ng = mid;
    }
    ans += ok;
    n -= ok*a.at(i);
    n += ok*b.at(i);
  }
  cout << ans << endl;;

  return 0;
}
