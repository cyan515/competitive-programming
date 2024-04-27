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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  ll n;cin>>n;
  map<ll,ll> mp;
  mp[n]++;
  ll ans = 0;
  while(mp.size()) {
    auto it = mp.end();
    it--;
    auto [k,v] = *it;
    ans += k*v;
    if(k/2>1) mp[k/2] += v;
    if((k+1)/2>1) mp[(k+1)/2] += v;
    it = mp.end();
    it--;
    mp.erase(it);
  }
  cout << ans << endl;

  exit(0);
}
