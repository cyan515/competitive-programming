#include <bits/stdc++.h>
#include <atcoder/math>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

long long powll(long long BASE, long long EXPONENT) {
  long long RET = 1;
  while (EXPONENT > 0) {
    if (EXPONENT & 1) RET = RET * BASE;
    BASE = BASE * BASE;
    EXPONENT >>= 1;
  }
  return RET;
}
int main() {
  ll n;cin>>n;
  ll l,r;cin>>l>>r;
  map<ll,vector<pair<ll,pair<ll,ll>>>> mp;
  rep(i,n) rep(j,n) {
    mp[powll(2,i)*j].push_back(pair(powll(2,i)*(j+1)-1,pair(i,j)));
  }
  for(auto& [k,v] : mp) {
    sort(all(v));
    v.push_back(pair(LINF,pair(-1,-1)));
  }
  ll cur = l;
  ll ans = 0;
  while(1) {
    auto& v = mp.at(cur);
    auto it = upper_bound(all(v),pair(r,pair(LINF,LINF)));
    it--;
    auto [val,ij] = *it;
    auto [i,j] = ij;
    cout << "? " << i << " " << j << endl;
    int a;cin>>a;
    ans += a;
    ans %= 100;
    cur = val;
    if(cur==r) break;
    cur++;
  }
  ans %= 100;
  cout << "! " << ans << endl;

  return 0;
}
