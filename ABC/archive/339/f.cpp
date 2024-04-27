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

using S = pair<ll,ll>;

S op(S a,S b) {
  return {min(a.first,b.first),a.second+b.second};
}

S e() {
  return {LINF,0};
}

S mapping(ll f,S a) {
  if(a.first<=f) return {a.first,a.first};
  else return {a.first,0};
}

ll composition(ll f,ll g) {
  return max(f,g);
}

ll id() {
  return LINF;
}

int main() {
  int n;cin>>n;
  vector<ll> a(n);cin>>a;
  int Q;cin>>Q;
  int x = -1;
  lazy_segtree<S,op,e,ll,mapping,composition,id> seg(n);
  rep(i,n) seg.set(i,{a.at(i),0});
  while(Q--) {
    ll s,t,u;cin>>s>>t>>u;
    if(x!=-1) {
      s ^= x;
      t ^= x;
      u ^= x;
    }
    s--;
    seg.apply(0,n,u);
    cout << seg.prod(s,t).second << endl;
  }

  exit(0);
}
