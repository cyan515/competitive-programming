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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}

int main() {
  ll n,m;cin>>n>>m;
  vector<string> s(n);cin>>s;
  int ans = INF;
  rep(bit,1<<n) {
    vector<bool> flg(m,false);
    rep(i,n) rep(j,m) {
      if((bit&(1<<i))==0) continue;
      if(s.at(i).at(j) == 'o') flg.at(j) = true;
    }
    bool ok = true;
    rep(i,m) ok &= flg.at(i);
    if(ok) chmin(ans,__popcount(bit));
  }
  cout << ans << endl;

  return 0;
}
