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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  ll n;cin>>n;
  vector<ll> a(n);cin>>a;
  map<set<int>,ll> mp;
  ll z = 0;
  rep(i,n) {
    set<int> st;
    int x = a.at(i);
    if(x==0) {
      z++;
      continue;
    }
    for(ll j=2;j*j<=x;j++) {
      bool flg = false;
      while(x%j==0) {
        x /= j;
        flg = !flg;
      }
      if(flg) st.insert(j);
    }
    if(x>1) st.insert(x);
    mp[st]++;
  }
  if(z==n) {
    cout << n*(n-1)/2 << endl;
    return 0;
  }
  ll ans = z*(n-z)+z*(z-1)/2;
  for(auto [k,v] : mp) {
    ans += v*(v-1)/2;
  }
  cout << ans << endl;

  return 0;
}
