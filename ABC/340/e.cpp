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
using S = ll;
using F = ll;

ll op(ll a,ll b) {
  return 0LL;
}

ll e() {
  return 0LL;
}

ll mapping(ll a,ll b) {
  return a+b;
}

ll composit(ll a,ll b) {
  return a+b;
}

ll id() {
  return 0LL;
}

int main() {
  int n;cin>>n;
  int m;cin>>m;
  vector<ll> a(n);cin>>a;
  vector<ll> b(m);cin>>b;
  lazy_segtree<S,op,e,F,mapping,composit,id> st(a);
  for(auto ele : b) {
    ll cnt = st.get(ele);
    st.set(ele,0LL);
    ll lp = cnt/n;
    if(lp) st.apply(0,n,lp);
    ll rem = cnt%n;
    if(ele+1<n) {
      if(ele+1+rem<n) st.apply(ele+1,ele+1+rem,1);
      else {
        st.apply(ele+1,n,1);
        st.apply(0,ele+1+rem-n,1);
      }
    } else {
      st.apply(0,rem,1);
    }
  }
  rep(i,n) {
    cout << st.get(i) << " ";
  }
  cout << endl;

  exit(0);
}
