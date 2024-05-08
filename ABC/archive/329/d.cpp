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
using S = pair<int,int>;
S op(S a,S b) {
  return max(a,b);
}
S e() {
  return pair(-INF,-INF);
}

int main() {
  ll n,m;cin>>n>>m;
  vector<ll> a(m);cin>>a;
  rep(i,m) a.at(i)--;
  segtree<S,op,e> st(n);
  rep(i,n) st.set(i,pair(0,-i));
  rep(i,m) {
    st.set(a.at(i),pair(st.get(a.at(i)).first+1,st.get(a.at(i)).second));
    auto [_,idx] = st.all_prod();
    cout << -idx+1 << endl;
  }

  return 0;
}
