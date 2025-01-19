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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n,m;cin>>n>>m;
  vector<ll> p(n);cin>>p;
  sort(all(p));
  ll ok = 0;
  ll ng = 10;
  while(abs(ok-ng)>1) {
    ll mid = (ok+ng)/2;
    ll cnt = 0;
    bool flg = false;
    rep(i,n) {
      ll okk = 0;
      ll ngg = LINF;
      while(abs(okk-ngg)>1) {
        ll midd = (okk+ngg)/2;
        ll tmp = (2*midd+1)*p.at(i);
        if(0<tmp&&tmp<mid) okk = midd;
        else ngg = midd;
      }
      cnt += (okk+1)*(ok+1)*p.at(i);
      flg |= cnt<0;
    }
    if(!flg&&cnt<=m) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;

  return 0;
}
