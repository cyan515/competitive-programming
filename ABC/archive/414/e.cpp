#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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

// https://atcoder.jp/contests/abc230/submissions/45654854
mint calc(ll n) {
  vector<pair<ll,ll>> a;
  for(ll i=1;i*i<=n;i++) {
    ll j = n/i;
    a.emplace_back(i,j);
    a.emplace_back(j,i);
  }
  sort(all(a));
  reverse(all(a));
  mint ans = n;
  rep(i,a.size()-1) {
    ans += a.at(i).second * (a.at(i).first-a.at(i+1).first);
  }
  return ans;
}

int main() {
  ll n;cin>>n;
  mint ans = mint(n)*(n+1)/2;
  mint x = calc(n);
  ans -= x;
  cout << ans.val() << endl;

  return 0;
}
