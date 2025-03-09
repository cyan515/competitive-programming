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
  ll n,x;cin>>n>>x;
  vector<ll> u(n),d(n);
  rep(i,n) cin>>u.at(i)>>d.at(i);
  ll ok = 0;
  ll ng = LINF;
  while(abs(ok-ng)>1) {
    ll mid = (ok+ng)/2;
    ll hi = LINF;
    ll lo = 0;
    bool flg = true;
    rep(i,n) {
      if(u.at(i)+d.at(i)<mid) {
        flg = false;
        break;
      }
      if(u.at(i)+d.at(i)==mid) hi = d.at(i),lo = d.at(i);
      else {
        ll nhi = min(hi+x,d.at(i));
        ll nlo = max({lo-x,mid-u.at(i),0LL});
        swap(hi,nhi);
        swap(lo,nlo);
      }
      flg &= hi>=lo;
    }
    if(flg) ok = mid;
    else ng = mid;
  }
  ll sum = 0;
  rep(i,n) sum += u.at(i)+d.at(i);
  ll ans = sum - ok*n;
  cout << ans << endl;

  return 0;
}
