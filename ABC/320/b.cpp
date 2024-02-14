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
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s;cin>>s;
  int n = s.length();
  ll ans = -1;
  rep(i,n) {
    reps(j,i,n) {
      bool flg = true;
      reps(k,i,j+1) {
        flg &= s.at(k) == s.at(j-k+i);
      }
      if(flg) ans = max(ans,j-i+1);
    }
  }
  cout << ans << endl;

  exit(0);
}
