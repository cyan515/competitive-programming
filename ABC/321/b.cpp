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
  int x;cin>>x;
  vector<int> a(n-1);
  rep(i,n-1) cin>>a.at(i);
  sort(all(a));
  int mi = INF;
  int ma = -1;
  int sum = 0;
  rep(i,n-1) {
    sum += a.at(i);
    mi = min(mi,a.at(i));
    ma = max(ma,a.at(i));
  }
  sum -=mi;
  sum -=ma;
  if(sum+mi>=x) {
    cout << 0 << endl;
  } else {
    int dif = x - sum;
    if(dif > ma) cout << -1 << endl;
    else cout << dif << endl;
  }

  exit(0);
}
