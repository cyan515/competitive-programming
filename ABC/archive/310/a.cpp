#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  int n;cin>>n;
  int p,q;cin>>p>>q;
  vector<int> d(n);
  rep(i,n) cin>>d.at(i);
  int mi = INF;
  rep(i,n) mi = min(d.at(i),mi);
  if(p<q+mi) cout << p << endl;
  else cout << q+mi << endl;

  exit(0);
}
