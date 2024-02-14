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

int main() {
  int n;cin>>n;
  vector<ll> a(n);
  rep(i,n) cin>>a.at(i);
  vector<ll> b = a;
  sort(all(b));
  vector<ll> sum(n+1,0);
  rep(i,n) {
    sum.at(n-1-i) += sum.at(n-i);
    sum.at(n-1-i) += b.at(n-1-i);
  }
  rep(i,n) {
    int idx = upper_bound(all(b),a.at(i)) - b.begin();
    cout << sum.at(idx) << " ";
  }
  cout << endl;

  exit(0);
}
