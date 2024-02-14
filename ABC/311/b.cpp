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
  int d;cin>>d;
  vector<string> s(n);
  rep(i,n) cin>>s.at(i);
  int ans = -INF;
  rep(i,d) {
    int cnt = 0;
    rep(j,n) {
      if(i==d || s.at(j).at(i)=='x') break;
      if(j==n-1) {
        j=-1;
        i++;
        cnt++;
      }
    }
    ans = max(ans,cnt);
  }
  cout << ans << endl;

  exit(0);
}
