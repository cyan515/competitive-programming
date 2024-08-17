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

int main() {
  ll n,k;cin>>n>>k;
  vector<ll> r(n);cin>>r;
  vector<int> ans(n);
  int sum = 0;
  auto f = [&](auto f,int p) -> void {
    if(p==n) {
      if(sum%k==0) {
        rep(i,n) {
          if(i) cout << " ";
          cout << ans.at(i);
        }
        cout << endl;
      }
      return;
    }
    rep(i,r.at(p)) {
      ans.at(p) = i+1;
      sum += i+1;
      f(f,p+1);
      sum -= i+1;
    }
  };
  f(f,0);

  return 0;
}
