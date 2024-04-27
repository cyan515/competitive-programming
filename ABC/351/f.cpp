#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
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

ll op(ll a,ll b) {
  return a+b;
}
ll e() {
  return 0;
}

int main() {
  ll n;cin>>n;
  vector<ll> a(n);cin>>a;
  vector<ll> b = a;
  sort(all(b));
  b.erase(unique(all(b)),b.end());
  vector<ll> aa(n);
  rep(i,n) {
    aa.at(i) = lower_bound(all(b),a.at(i))-b.begin();
  }
  int m = b.size();
  ll ans = 0;
  {
    segtree<ll,op,e> st(m+1);
    rep(i,n) {
      ll cnt = st.prod(0,aa.at(i));
      ans += cnt*a.at(i);
      st.set(aa.at(i),st.get(aa.at(i))+1);
    }
  }
  {
    segtree<ll,op,e> st(m+1);
    for(int i=n-1;i>=0;i--) {
      ll cnt = st.prod(aa.at(i)+1,m+1);
      ans -= cnt*a.at(i);
      st.set(aa.at(i),st.get(aa.at(i))+1);
    }
  }
  cout << ans << endl;

  return 0;
}
