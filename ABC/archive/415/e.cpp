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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int h,w;cin>>h>>w;
  bool sp = false;
  if(h<w) {
    swap(h,w);
    sp = true;
  }
  vector a(h,vector<ll>(w));
  if(!sp) rep(i,h) cin>>a.at(i);
  else {
    rep(i,w) rep(j,h) {
      cin>>a.at(j).at(i);
    }
  }
  vector<ll> p(h+w-1);cin>>p;
  ll ok = LINF-1;
  ll ng = -1;
  while(abs(ok-ng)>1) {
    ll mid = (ok+ng)/2;
    vector dp(h,vector<ll>(w,-LINF));
    dp.at(0).at(0) = mid;
    rep(i,h) rep(j,w) {
      if(i&&dp.at(i-1).at(j)-p.at(i+j-1)+a.at(i-1).at(j)>=0) {
        chmax(dp.at(i).at(j),dp.at(i-1).at(j)-p.at(i+j-1)+a.at(i-1).at(j));
      }
      if(j&&dp.at(i).at(j-1)-p.at(i+j-1)+a.at(i).at(j-1)>=0) {
        chmax(dp.at(i).at(j),dp.at(i).at(j-1)-p.at(i+j-1)+a.at(i).at(j-1));
      }
    }
    if(dp.at(h-1).at(w-1)+a.at(h-1).at(w-1)>=p.back()) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;

  return 0;
}
