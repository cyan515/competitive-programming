#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n;cin>>n;
  string s;cin>>s;
  vector<ll> cnt(26,0);
  ll x = 1;
  rep(i,n) {
    while(i<n-1&&s.at(i)==s.at(i+1)) {
      i++;
      x++;
    }
    cnt.at(s.at(i)-'a') = max(cnt.at(s.at(i)-'a'),x);
    x = 1;
  }
  ll ans = 0;
  rep(i,26) {
    ans += cnt.at(i);
  }
  cout << ans << endl;

  return 0;
}
