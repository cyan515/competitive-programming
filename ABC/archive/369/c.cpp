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
  ll n;cin>>n;
  vector<ll> a(n);cin>>a;
  vector<ll> b(n-1);
  rep(i,n-1) {
    b.at(i) = a.at(i+1)-a.at(i);
  }
  ll ans = n;
  ll cnt = 1;
  rep(i,n-1) {
    if(i==n-2||b.at(i)!=b.at(i+1)) {
      ans += (1+cnt)*cnt/2;
      cnt = 1;
    } else {
      cnt++;
    }
  }
  cout << ans << endl;

  return 0;
}
