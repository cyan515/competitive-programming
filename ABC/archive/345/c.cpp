#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  string s;cin>>s;
  int n = s.size();
  vector<int> cnt(26,0);
  ll ans = 0;
  bool same = false;
  rep(i,n) {
    ans += i-cnt.at(s.at(i)-'a');
    if(cnt.at(s.at(i)-'a')>0) same = true;
    cnt.at(s.at(i)-'a')++;
  }
  if(same) ans++;
  cout << ans << endl;

  return 0;
}
