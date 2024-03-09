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
using S = tuple<int,int,int,int>;

S op(S a,S b) {
  auto [w,x,y,z] = a;
  auto [s,t,u,v] = b;
  set<int> st = {w,x,s,t,0,-1};
  vector<int> vec;
  for(auto ele : st) {
    vec.push_back(ele);
  }
  reverse(all(vec));
  int mac = 0;
  int sec = 0;
  if(w==vec.at(0)) mac += y;
  if(s==vec.at(0)) mac += u;
  if(w==vec.at(1)) sec += y;
  if(s==vec.at(1)) sec += u;
  if(x==vec.at(1)) sec += z;
  if(t==vec.at(1)) sec += v;
  return tuple(vec.at(0),vec.at(1),mac,sec);
}
S e() {
  return tuple(0,-1,0,0);
}

int main() {
  int n;cin>>n;
  int Q;cin>>Q;
  vector<S> a(n);
  rep(i,n) {
    int tmp;cin>>tmp;
    a.at(i) = tuple(tmp,-1,1,1);
  }
  segtree<S,op,e> st(a);
  while(Q--) {
    int t;cin>>t;
    if(t==1) {
      int p,x;cin>>p>>x;p--;
      st.set(p,tuple(x,-1,1,1));
    } else {
      int l,r;cin>>l>>r;l--;
      auto [w,x,y,z] = st.prod(l,r);
      if(x<=0) cout << 0 << endl;
      else cout << z << endl;
    }
  }

  return 0;
}
