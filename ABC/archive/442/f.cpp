#include <bits/stdc++.h>
#include <atcoder/segtree>
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
using S = int;
S op(S a,S b) {
  return min(a,b);
}
S e() {
  return INF;
}

int main() {
  ll n;cin>>n;
  vector<string> s(n);cin>>s;
  vector<segtree<S,op,e>> dp(n+1,segtree<S,op,e>(n+1));
  rep(i,n+1) dp.at(0).set(i,0);
  rep(i,n) {
    ll cnt = 0;
    rep(j,n) {
      cnt += !!(s.at(i).at(j)=='.');
    }
    rep(j,n) {
      ll x = dp.at(i+1).get(j);
      ll prd = dp.at(i).prod(j,n+1);
      if(prd!=INF && chmin(x,prd+cnt)) {
        dp.at(i+1).set(j,x);
      }
      if(s.at(i).at(j)=='.') cnt--;
      else cnt++;
    }
    dp.at(i+1).set(n,dp.at(i).get(n)+cnt);
  }
  cout << dp.at(n).all_prod() << endl;

  return 0;
}
