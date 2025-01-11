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
  ll n,m,a,b;cin>>n>>m>>a>>b;
  vector<ll> l(m),r(m);
  rep(i,m) cin>>l.at(i)>>r.at(i);
  vector<int> move;
  int mm = 0;
  reps(i,a,b+1) mm |= 1<<i;
  rep(i,b+1) {
    if((mm&(1<<i))==0) continue;
    mm |= mm<<1;
  }
  mm &= 1<<(b+1);
  move.push_back(mm);
  while(1) {
    int nx = 0;
    rep(i,b+1) {
      if((move.back()&(1<<i))==0) continue;
      nx |= (move.back()>>(b-i));
    }
  }

  return 0;
}
