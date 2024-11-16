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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = __gnu_pbds::tree<ll,null_type,greater<ll>,rb_tree_tag,tree_order_statistics_node_update>;

int main() {
  ll n,m,k;cin>>n>>m>>k;
  vector<ll> a(n);cin>>a;
  ll r = k;
  rep(i,n) r -= a.at(i);
  vector<ll> b = a;
  fenwick_tree<ll> ft(n);
  sort(all(b));
  rep(i,n) ft.add(i,b.at(i));
  rep(i,n) {
    if(i) cout << " ";
    ll ok = r+1;
    ll ng = -1;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      ll x = a.at(i)+mid;
      ll up = b.end() - upper_bound(all(b),x);
      ll rival = m - up;
      if(rival<=0) {
        ng = mid;
        continue;
      }
      ll right = n-up;
      ll left = right - rival;
      ll sum = 0;
      if(b.at(left)<a.at(i)) {
        left--;
        sum -= a.at(i);
      } else if(b.at(left)==a.at(i)) {
        if(left==0) {
          ok = mid;
          continue;
        } else if(b.at(left)!=b.at(left-1)) {
          left--;
          sum -= a.at(i);
        }
      }
      if(left<0) {
        ok = mid;
        continue;
      }
      sum += ft.sum(left,right);
      ll rem = r - mid;
      if(rival*(x+1)-sum>rem) ok = mid;
      else ng = mid;
    }
    if(ok==r+1) cout << -1;
    else cout << ok;
  }
  cout << endl;

  return 0;
}
