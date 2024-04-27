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
  ll n;cin>>n;
  ll d;cin>>d;
  ll p;cin>>p;
  vector<ll> f(n);
  rep(i,n) cin>>f.at(i);
  sort(all(f));
  reverse(all(f));
  vector<ll> sum_d;
  ll tmp = 0;
  ll sum = 0;
  ll buy = 0;
  rep(i,n) {
    tmp++;
    sum += f.at(i);
    if(tmp==d || i==n-1) {
      tmp = 0;
      if(sum<=p) break;
      buy++;
      sum = 0;
    }
  }
  reverse(all(f));
  ll ans = 0;
  rep(i,n-buy*d) {
    ans += f.at(i);
  }
  ans += buy*p;
  cout << ans << endl;

  exit(0);
}
