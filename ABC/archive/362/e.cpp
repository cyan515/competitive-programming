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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  ll n;cin>>n;
  vector<ll> a(n+1,0);
  rep(i,n) cin>>a.at(i+1);
  vector dp(n+1,vector(n+1,map<ll,mint>()));
  dp.at(0).at(0)[LINF] = 1;
  rep(i,n) rep(l,n+1) {
    for(auto& [d,cnt] : dp.at(i).at(l)) {
      reps(j,i+1,n+1) {
        if(a.at(j)-a.at(i)!=d && d!=LINF) continue;
        if(l==0) dp.at(j).at(l+1)[LINF] += cnt;
        else dp.at(j).at(l+1)[a.at(j)-a.at(i)] += cnt;
      }
    }
  }
  reps(l,1,n+1) {
    if(l!=1) cout << " ";
    mint ans = 0;
    rep(i,n+1) for(auto& [k,v] : dp.at(i).at(l)) ans += v;
    cout << ans.val();
  }
  cout << endl;

  return 0;
}
