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
  int m;cin>>m;
  vector<string> c(n);
  rep(i,n) cin>>c.at(i);
  vector<string> d(m);
  rep(i,m) cin>>d.at(i);
  int p0;cin>>p0;
  vector<int> p(m);
  rep(i,m) cin>>p.at(i);
  int sum = 0;
  rep(i,n) {
    int tmp = p0;
    rep(j,m) {
      if(c.at(i)==d.at(j)) tmp = p.at(j);
    }
    sum += tmp;
  }
  cout << sum << endl;

  exit(0);
}
