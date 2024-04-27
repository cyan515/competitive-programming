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
using S = tuple<bool,bool,bool>;

S op(S a,S b) {
  return {get<0>(a),get<1>(b),get<2>(a)&get<2>(b)&(get<1>(a)|get<0>(b))};
}

S e() {
  return {true,true,true};
}


int main() {
  int n,Q;cin>>n>>Q;
  string s;cin>>s;
  segtree<S,op,e> st(n);
  rep(i,n) {
    bool a = false;
    bool b = false;
    if(i==0) a = true;
    else if(s.at(i)!=s.at(i-1)) a = true;
    if(i==n-1) b = true;
    else if(s.at(i)!=s.at(i+1)) b = true;
    st.set(i, {a,b,true});
  }
  while(Q--) {
    int t;cin>>t;
    int l,r;cin>>l>>r;l--;
    if(t==1) {
      r--;
      auto a = st.get(l);
      st.set(l,{l==0?true:!get<0>(a),get<1>(a),get<2>(a)});
      if(l!=0) {
        a = st.get(l-1);
        st.set(l-1,{get<0>(a),!get<1>(a),get<2>(a)});
      }
      a = st.get(r);
      st.set(r,{get<0>(a),r==n-1?true:!get<1>(a),get<2>(a)});
      if(r!=n-1) {
        a = st.get(r+1);
        st.set(r+1,{!get<0>(a),get<1>(a),get<2>(a)});
      }
    } else {
      S res = st.prod(l,r);
      if(get<2>(res)) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }

  return 0;
}
