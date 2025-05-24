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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
using S = ll;
S op(S a,S b) {
  return max(a,b);
}
S e() {
  return -LINF;
}
int main() {
  int n;cin>>n;
  vector<ll> a(n);cin>>a;
  segtree<S,op,e> seg(n);
  rep(i,n) seg.set(i,a.at(i));
  vector<ll> ans(n,0);
  rep(i,n) {
    int l,r;
    {
      int ok = i+1;
      int ng = n+1;
      while(abs(ok-ng)>1) {
        int mid = (ok+ng)/2;
        ll val = seg.prod(i,mid);
        if(val==a.at(i)) ok = mid;
        else ng = mid;
      }
      r = ok;
    }
    {
      int ok = i;
      int ng = -1;
      while(abs(ok-ng)>1) {
        int mid = (ok+ng)/2;
        ll val = seg.prod(mid,i+1);
        if(val==a.at(i)) ok = mid;
        else ng = mid;
      }
      l = ok;
    }
    int mi = max(i-l+1,r-i+1)-1;
    rep(j,mi) {
      ans.at(j) += a.at(i)*(j+1);
    }
  }
  rep(i,n) cout << ans.at(i) << endl;

  return 0;
}
