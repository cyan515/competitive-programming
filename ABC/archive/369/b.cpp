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
  int n;cin>>n;
  int l = -1;
  int r = -1;
  int ans = 0;
  rep(i,n) {
    int a;cin>>a;
    char c;cin>>c;
    if(c=='L') {
      if(l!=-1) {
        ans += abs(l-a);
      }
      l = a;
    } else {
      if(r!=-1) {
        ans += abs(r-a);
      }
      r = a;
    }
  }
  cout << ans << endl;

  return 0;
}
