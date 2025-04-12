#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const ll MOD = 1000000000LL;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
ll op(ll a,ll b) {
  return (a+b)%MOD;
}
ll e() {
  return 0LL;
}

int main() {
  ll n,k;cin>>n>>k;
  if(n<k) {
    cout << 1 << endl;
    return 0;
  }
  
  segtree<ll,op,e> dp(n+1);
  rep(i,k) dp.set(i,1);
  reps(i,k,n+1) {
    dp.set(i,dp.prod(i-k,i));
  }
  cout << dp.get(n) << endl;

  return 0;
}
