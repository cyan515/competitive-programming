#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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
  int n,k;cin>>n>>k;
  vector<int> a(n);cin>>a;
  int ans = 0;
  int cnt = 0;
  rep(i,n) {
    if(cnt+a.at(i)>k) {
      cnt = a.at(i);
      ans++;
    } else cnt+=a.at(i);
  }
  ans++;
  cout << ans << endl;

  return 0;
}
