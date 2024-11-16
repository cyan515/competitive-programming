#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using mint = modint998244353;
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
  ll n,m,k;cin>>n>>m>>k;
  vector<int> x(m),y(m);
  rep(i,m) cin>>x.at(i)>>y.at(i);
  rep(i,m) x.at(i)--,y.at(i)--;
  vector<mint> dp(n,0);
  dp.at(0)++;
  rep(i,k) {
    map<ll,mint> mp;
    rep(j,m) {
      mp[(y.at(j)+n*k-1-i)%n] += dp.at((x.at(j)+n*k-i)%n);
    }
    for(auto [k,v] : mp) {
      dp.at(k) += v;
    }
  }
  mint ans = 0;
  rep(i,n) ans += dp.at(i);
  cout << ans.val() << endl;

  return 0;
}
