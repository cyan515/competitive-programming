#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T;cin>>T;
  while(T--) {
    ll n;cin>>n;
    ll m;cin>>m;
    vector<ll> a(n);
    a.at(0) = 1;
    rep(i,n-1) cin>>a.at(i+1);
    vector<ll> b(n);
    rep(i,n) cin>>b.at(i);
    multiset<ll> bst;
    rep(i,n) bst.insert(b.at(i));
    sort(all(a));
    ll bmi = LINF;
    rep(i,n) {
      auto it = bst.upper_bound(a.at(i));
      if(it == bst.end()) break;
      bmi = min(bmi,*it);
      bst.erase(it);
    }
    cout << bst.size() << "\n";
    ll ans = 0;
  }

  exit(0);
}
