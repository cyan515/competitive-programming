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
  int n;cin>>n;
  rep(i,n+1) {
    int ans = -1;
    for(int j=1;j<10;j++) {
      if(n%j==0 && i%(n/j)==0) {
        ans = j;
        break;
      }
    }
    if(ans==-1) cout << "-";
    else cout << ans;
  }
  cout << endl;

  exit(0);
}
