#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  ll l,r;cin>>l>>r;
  vector<pair<ll,ll>> ans;
  ll a = l;
  while(1) {
    ll x = 1;
    ll ma = -LINF;
    while(1) {
      if(a%x) {
        break;
      }
      ll s = a/x;
      if(x*(s+1)>r) {
        break;
      }
      chmax(ma,x*(s+1));
      x *= 2;
    }
    ans.push_back(pair(a,ma));
    if(ma==r) break;
    a = ma;
  }
  cout << ans.size() << endl;
  rep(i,ans.size()) cout << ans.at(i).first << " " << ans.at(i).second << endl;

  return 0;
}
