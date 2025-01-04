#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace atcoder;
// using mint = modint998244353;
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
// https://atcoder.jp/contests/typical90/tasks/typical90_ay
int main() {
  int n,k;cin>>n>>k;
  ll p;cin>>p;
  vector<ll> a(n);cin>>a;
  vector<vector<ll>> x(n+1),y(n+1);
  rep(bit,1<<(n/2)) {
    ll s = 0;
    rep(i,n/2) {
      if((bit&(1<<i))>0) s += a.at(i);
    }
    x.at(__popcount(bit)).push_back(s);
  }
  rep(bit,1<<(n-n/2)) {
    ll s = 0;
    rep(i,n-n/2) {
      if((bit&(1<<i))>0) s += a.at(n/2+i);
    }
    y.at(__popcount(bit)).push_back(s);
  }
  rep(i,n) sort(all(x.at(i))),sort(all(y.at(i)));
  ll ans = 0;
  rep(i,n+1) {
    for(auto xx:x.at(i)){
      int j = k-i;
      if(j<0) continue;
      int cnt = upper_bound(all(y.at(j)),p-xx)-y.at(j).begin();
      ans+=cnt;
    }
  }
  cout << ans << endl;
  
  return 0;
}
