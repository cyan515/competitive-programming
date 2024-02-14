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
  ll n;cin>>n;
  vector<ll> a(n);
  rep(i,n) cin>>a.at(i);
  sort(a.begin(),a.end());
  ll sum = 0;
  rep(i,n) sum += a.at(i);
  ll l = sum / n;
  ll r = l+1;
  ll lcnt = 0;
  while(lcnt*l+(n-lcnt)*r!=sum) {
    lcnt++;
  }
  ll ans = 0;
  // sum = 0;
  // rep(i,n) {
  //   ans += abs(l-a.at(i));
  //   sum += l;
  // }
  
  rep(i,n) {
    if(i<lcnt) ans += abs(l-a.at(i));
    else ans += abs(a.at(i)-r);
  }
  cout << ans/2 << endl;

  exit(0);
}
