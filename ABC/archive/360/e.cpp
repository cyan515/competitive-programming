#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
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

int main() {
  ll n,k;cin>>n>>k;
  if(n==1) {
    cout << 1 << endl;
    return 0;
  }
  mint ans = 1;
  mint nc = mint(1)/mint(n)/mint(n)+mint(n-1)*mint(n-1)/mint(n)/mint(n);
  mint c = 1 - nc;
  mint sum = mint(1+n)*n/2;
  rep(_,k) {
    ans = nc*ans + c*mint(sum-ans)/mint(n-1);
  }
  cout << ans.val() << endl;

  return 0;
}
