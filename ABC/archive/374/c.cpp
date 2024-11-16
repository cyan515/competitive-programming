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
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  vector<ll> k(n);cin>>k;
  ll ans = LINF;
  rep(bit,1<<n) {
    ll x = 0;
    ll y = 0;
    rep(i,n) {
      if((bit&(1<<i))!=0) x += k.at(i);
      else y += k.at(i);
    }
    ans = min(ans,max(x,y));
  }
  cout << ans << endl;

  return 0;
}
