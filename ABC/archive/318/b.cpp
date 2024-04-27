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
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  vector<int> d(n);
  rep(i,n) cin>>a.at(i)>>b.at(i)>>c.at(i)>>d.at(i);
  vector ans(101,vector<bool>(101,false));
  rep(i,n) reps(x,a.at(i),b.at(i)) reps(y,c.at(i),d.at(i)) {
    ans.at(x).at(y) = true;
  }
  int cnt = 0;
  rep(i,101) rep(j,101) if(ans.at(i).at(j)) cnt++;
  cout << cnt << endl;

  exit(0);
}
