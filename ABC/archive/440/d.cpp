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
  ll n,Q;cin>>n>>Q;
  vector<ll> a(n);cin>>a;
  sort(all(a));
  while(Q--) {
    ll x,y;cin>>x>>y;
    auto it = lower_bound(all(a),x)-a.begin();
    ll ok = LINF;
    ll ng = x-1;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      auto it2 = upper_bound(all(a),mid)-a.begin();
      ll diff = it2-it;
      ll nth = mid - x + 1;
      nth -= diff;
      if(nth>=y) ok = mid;
      else ng = mid;
    }
    cout << ok << endl;
  }

  return 0;
}
