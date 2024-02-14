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
  cin.tie(0) -> sync_with_stdio(0);
  int n;cin>>n;
  vector<string> s(n);
  rep(i,n) cin>>s.at(i);
  vector<pair<int,int>> ans(n);
  rep(i,n) {
    int cnt = 0;
    rep(j,n) {
      if(s.at(i).at(j)=='o') cnt++;
    }
    ans.at(i) = make_pair(-cnt,i+1);
  }
  sort(all(ans));
  rep(i,n) cout << ans.at(i).second << " ";
  cout << endl;

  exit(0);
}
