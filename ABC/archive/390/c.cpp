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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}

int main() {
  int h,w;cin>>h>>w;
  vector<string> s(h);cin>>s;
  ll l = INF;
  ll r = -INF;
  ll u = INF;
  ll d = -INF;
  rep(i,h) rep(j,w) {
    if(s.at(i).at(j)=='#') {
      chmin(l,j);
      chmax(r,j);
      chmin(u,i);
      chmax(d,i);
    }
  }
  reps(i,u,d+1) reps(j,l,r+1) {
    if(s.at(i).at(j)=='.') {
      cout << No << endl;
      return 0;
    }
  }
  cout << Yes << endl;

  return 0;
}
