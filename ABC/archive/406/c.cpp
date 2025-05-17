#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  vector<int> p(n);cin>>p;
  ll l = 0;
  ll r = 1;
  ll ans = 0;
  fenwick_tree<ll> ft(n);
  rep(i,n-1) {
    if(p.at(i)<p.at(i+1)) ft.add(i,1);
  }
  while(l<n&&r<=n) {
    while(r<n&&p.at(r-1)>p.at(r)) r++;
    ll x,y;
    if(abs(r-l)==1) {
      l = r;
      r++;
      continue;
    }
    if(r==n) break;
    {
      ll ok = l+1;
      ll ng = -1;
      while(abs(ok-ng)>1) {
        ll mid = (ok+ng)/2;
        ll cnt = ft.sum(mid,l);
        if(cnt==abs(mid-l)) ok = mid;
        else ng = mid;
      }
      x = abs(ok-l);
    }
    {
      ll ok = r;
      ll ng = n;
      while(abs(ok-ng)>1) {
        ll mid = (ok+ng)/2;
        ll cnt = ft.sum(r,mid);
        if(cnt==abs(r-mid)) ok = mid;
        else ng = mid;
      }
      y = abs(ok-r)+1;
    }
    ans += x*y;
    l = r;
    r++;
  }
  cout << ans << endl;

  return 0;
}
