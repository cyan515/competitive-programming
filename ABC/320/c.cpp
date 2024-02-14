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
  int m;cin>>m;
  vector<string> s(3);
  cin>>s.at(0)>>s.at(1)>>s.at(2);
  int ans = INF;
  
  rep(i,10) {
    vector<int> ord = {0,1,2};
    do {
      int cnt = INF;
      char tgt = '0' + i;
      int idx = 0;
      rep(j,m*3) {
        if(s.at(ord.at(idx)).at(j%m)==tgt) {
          idx++;
          if(idx==3) {
            cnt = j;
            break;
          }
        }
      }
      ans = min(ans,cnt);
    } while(next_permutation(all(ord)));
  }
  if(ans!=INF) cout << ans << endl;
  else cout << -1 << endl;

  exit(0);
}
