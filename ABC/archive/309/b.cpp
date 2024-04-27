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
  vector<string> a(n);
  rep(i,n) cin>>a.at(i);

  int tmp = a.at(0).at(0);
  reps(i,1,n) {
    a.at(i-1).at(0) = a.at(i).at(0);
  }
  reps(i,1,n) {
    a.at(n-1).at(i-1) = a.at(n-1).at(i);
  }
  reps(i,1,n) {
    a.at(n-i).at(n-1) = a.at(n-i-1).at(n-1);
  }
  reps(i,1,n) {
    a.at(0).at(n-i) = a.at(0).at(n-i-1);
  }
  a.at(0).at(1) = tmp;
  rep(i,n) {
    rep(j,n) {
      cout << a.at(i).at(j);
    }
    cout << endl;
  }
  exit(0);
}
