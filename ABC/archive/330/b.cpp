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
  int n,l,r;cin>>n>>l>>r;
  vector<int> a(n);
  rep(i,n) cin>>a.at(i);
  vector<int> x(n);
  rep(i,n) {
    if(a.at(i)>=l && a.at(i)<=r) x.at(i) = a.at(i);
    else if(abs(l-a.at(i))>=abs(r-a.at(i))) x.at(i) = r;
    else x.at(i) = l;
  }
  rep(i,n) cout << x.at(i) << " ";
  cout << endl;

  exit(0);
}
