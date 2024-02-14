#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  int n;cin>>n;
  vector<int> p(n);
  rep(i,n) cin>>p.at(i);
  int ma = -INF;
  reps(i,1,n) ma=max(ma,p.at(i));
  if(p.at(0)>ma) cout << 0 << endl;
  else cout << ma+1-p.at(0) << endl;

  exit(0);
}
