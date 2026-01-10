#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
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
  ll n,m;cin>>n>>m;
  vector<ll> a(n),b(m);cin>>a>>b;
  fenwick_tree<ll> ft(m);
  sort(all(a));sort(all(b));
  rep(i,m) ft.add(i,b.at(i));
  mint ans = 0;
  rep(i,n) {
    auto it = lower_bound(all(b),a.at(i)) - b.begin();
    ll x = ft.sum(it,m) - a.at(i)*(m-it);
    ll y = a.at(i)*it - ft.sum(0,it);
    ans += x+y;
  }
  cout << ans.val() << endl;

  return 0;
}
