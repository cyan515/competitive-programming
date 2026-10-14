#include <bits/stdc++.h>
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
  int T;cin>>T;
  while(T--) {
    ll n,m;cin>>n>>m;
    vector<ll> a(n);cin>>a;
    sort(all(a));
    auto isok = [&](ll x) -> bool {
      {
        auto it = a.end() - lower_bound(all(a),x);
        it += m;
        if(it<=(n+m)/2) return false;
      }
      ll cnt = 0;
      auto dfs = [&](auto self,ll val) -> ll {
        if(val<x) return -1;
        ll ret = 0;
        if(x*2<=val) {
          cnt++;
          ret += self(self,val/2);
          ret += self(self,(val+1)/2);
          return ret;
        } else return 1;
      };
      ll sum = 0;
      rep(i,n) {
        if(a.at(i)<x) sum--;
        else sum += dfs(dfs,a.at(i));
      }
      return cnt >= m && sum>=0;
    };
    ll ok = 1;
    ll ng = 888;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      if(isok(mid)) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    cout << ok << endl;
  }

  return 0;
}
