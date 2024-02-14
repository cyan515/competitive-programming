#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

// https://atcoder.jp/contests/abc159/tasks/abc159_e
int main() {
  int h,w;cin>>h>>w;
  int k;cin>>k;
  vector<string> s(h);cin>>s;
  auto f = [&](int bit) -> int {
    int ans = 0;
    rep(i,h-1) if(bit & (1<<i)) ans++;
    vector<int> cnt(ans+1,0);
    int x = 0;
    int ret = ans;
    rep(j,w) {
      vector<int> d(ans+1,0);
      x = 0;
      rep(i,h) {
        if(s.at(i).at(j)=='1') d.at(x)++;
        if(bit & (1<<i)) x++;
      }
      bool ok = true;
      rep(i,ans+1) ok &= cnt.at(i)+d.at(i) <= k;
      if(ok) {
        rep(i,ans+1) cnt.at(i) += d.at(i);
      } else {
        ret++;
        rep(i,ans+1) cnt.at(i) = d.at(i);
      }
    }
    return ret;
  };
  int ans = INF;
  rep(bit,1<<(h-1)) {
    ans = min(ans,f(bit));
  }
  cout << ans << endl;
  
  return 0;
}
