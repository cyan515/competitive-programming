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
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i,n) cin>>a.at(i)>>b.at(i);
  rep(i,n) b.at(i)+=a.at(i);
  vector<pair<long double,int>> c(n);
  rep(i,n) c.at(i) = make_pair((long double)a.at(i)/b.at(i),-(i+1));
  sort(c.begin(),c.end());
  reverse(c.begin(),c.end());
  rep(i,n) cout << -c.at(i).second << " ";
  cout << endl;

  exit(0);
}
