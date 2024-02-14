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
  vector<ll> a(n);
  rep(i,n) cin>>a.at(i),a.at(i)--;
  ll ans = 0;
  map<ll,ll> r;
  map<ll,ll> l;
  reps(i,1,n) r[a.at(i)]++;
  vector<ll> p(n,0);
  ll p_sum = 0;
  reps(i,1,n) {
    r[a.at(i)]--;
    l[a.at(i-1)]++;
    if(r[a.at(i-1)]>0) {
      ll tmp = p.at(a.at(i-1));
      p.at(a.at(i-1)) = l[a.at(i-1)] * r[a.at(i-1)];
      p_sum -= tmp;
      p_sum += p.at(a.at(i-1));
    }
    if(r[a.at(i)]==0) {
      ll tmp = p.at(a.at(i));
      p.at(a.at(i)) = 0;
      p_sum -= tmp;
    }
    ans += p_sum - p.at(a.at(i));
  }
  cout << ans << endl;

  exit(0);
}
