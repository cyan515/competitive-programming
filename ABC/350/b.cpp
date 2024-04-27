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
  int n;cin>>n;
  int q;cin>>q;
  vector<bool> f(n,true);
  while(q--) {
    int t;cin>>t;t--;
    f.at(t) = !f.at(t);
  }
  int ans = 0;
  rep(i,n) if(f.at(i)) ans++;
  cout << ans << endl;

  return 0;
}
