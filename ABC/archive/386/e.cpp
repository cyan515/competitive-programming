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
  ll n,k;cin>>n>>k;
  bool flg = n/2<k;
  if(flg) k = n-k;
  vector<ll> a(n);cin>>a;
  ll ans = 0;
  ll x = 0;
  if(flg) rep(i,n) x ^= a.at(i);
  auto dfs = [&](auto f,int right,int cnt) -> void {
    if(cnt==k) {
      chmax(ans,x);
      return;
    }
    if(n-right<k-cnt) {
      return;
    }
    reps(i,right,n) {
      x ^= a.at(i);
      f(f,i+1,cnt+1);
      x ^= a.at(i);
    }
  };
  dfs(dfs,0,0);
  cout << ans << endl;

  return 0;
}
