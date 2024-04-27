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

using S = tuple<int,int,int,bool,int,int,int,bool>;
using F = bool;

S op(S a,S b) {
  int len_one = max(get<0>(a),max(get<0>(b),get<2>(a)+get<1>(b)));
  int l_one = get<3>(a) ? get<1>(a)+get<1>(b) : get<1>(a);
  int r_one = get<3>(b) ? get<2>(b)+get<2>(a) : get<2>(b);
  bool all_one = get<3>(a) && get<3>(b);
  
  int len_zero = max(get<4>(a),max(get<4>(b),get<6>(a)+get<5>(b)));
  int l_zero = get<7>(a) ? get<5>(a)+get<5>(b) : get<5>(a);
  int r_zero = get<7>(b) ? get<6>(b)+get<6>(a) : get<6>(b);
  bool all_zero = get<7>(a) && get<7>(b);
  
  return make_tuple(len_one,l_one,r_one,all_one,len_zero,l_zero,r_zero,all_zero);
}

S e() { return make_tuple(0,0,0,true,0,0,0,true); }

S mapping(F f,S x) {
  return f?make_tuple(get<4>(x),get<5>(x),get<6>(x),get<7>(x),get<0>(x),get<1>(x),get<2>(x),get<3>(x)):x;
}

F composition(F a,F b) { return a^b; }
F id() { return false; }

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n;cin>>n;
  int Q;cin>>Q;
  string s;cin>>s;
  lazy_segtree<
    S,
    op,
    e,
    F,
    mapping,
    composition,
    id> st(n);
  rep(i,n) {
    if(s.at(i)=='1') {
      st.set(i,make_tuple(1,1,1,true,0,0,0,false));
    } else {
      st.set(i,make_tuple(0,0,0,false,1,1,1,true));
    }
  }
  while(Q--) {
    int c,l,r;cin>>c>>l>>r;l--;
    if(c==1) {
      st.apply(l,r,true);
    } else {
      cout << get<0>(st.prod(l,r)) << endl;
    }
  }

  exit(0);
}
