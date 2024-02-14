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
  ll d;cin>>d;
  vector<ll> a;
  for(ll i=0;i*i<=d;i++) {
    a.push_back(i*i);
    if((i+1)*(i+1)>d) a.push_back((i+1)*(i+1));
  }
  ll ans = LINF;
  int n = a.size();
  rep(i,n) {
    auto it = upper_bound(all(a),d-a.at(i));
    ans = min(ans,abs(a.at(i)+*it-d));
    if(it!=a.begin()) it--;
    ans = min(ans,abs(a.at(i)+*it-d));
  }
  cout << ans << endl;

  exit(0);
}
