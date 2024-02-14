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
  int n,k;cin>>n>>k;
  vector<int> ans(n);
  int sum = 0;
  rep(i,k+1) {
    int res;
    cout << "?";
    rep(j,k+1) {
      if(i==j) continue;
      cout << " " << j+1;
    }
    cout << "\n";
    cin >> res;
    sum += res;
    sum %= 2;
    ans.at(i) = res;
  }
  rep(i,k+1) ans.at(i) = ans.at(i)==sum ? 0 : ans.at(i) = 1;
  string str = "?";
  rep(i,k-1) str += " " + to_string(i+1);
  str += " ";
  int base = 0;
  rep(i,k-1) base += ans.at(i),base %= 2;
  reps(i,k+1,n) {
    cout << str << i+1 << "\n";
    int res;
    cin >> res;
    ans.at(i) = base != res ? 1 : 0;
  }
  cout << "! ";
  rep(i,n) {
    cout << ans.at(i);
    if(i==n-1) cout << endl;
    else cout << " ";
  }

  exit(0);
}
