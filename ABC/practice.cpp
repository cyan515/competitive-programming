#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
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
// T,hw,color,count
using S = tuple<int,int,int,int>;
using F = S;

S op(S a,S b) {
  return a;
}

S e() {
  return tuple(0,0,0,0);
}
int h,w;
S mapping(F f, S s) {
  auto [a,b,c,d] = f;
  if(a==0) return s;
  auto [w,x,y,z] = s;
  if(a==w) {
    if(b==x) return tuple(w,x,y,0);
    return s;
  } else {
    return tuple(w,x,y,max(z-1,0));
  }
}

F comp(F f,F g) {
  return mapping(f,g);
}

F id() {
  return e();
}

int main() {
  ll m;cin>>h>>w>>m;
  vector<ll> hmemo(h,-1);
  vector<ll> wmemo(w,-1);
  lazy_segtree<S,op,e,F,mapping,comp,id> st(m+h);
  rep(i,h) {
    st.set(i,tuple(1,i,0,w));
  }
  reps(i,h,h+m) {
    int t,a,x;cin>>t>>a>>x;a--;
    if(t==1) {
      st.set(i,tuple(t,a,x,w));
      st.apply(hmemo.at(a)+1,i,tuple(t,a,x,w));
      hmemo.at(a) = i;
    } else {
      st.set(i,tuple(t,a,x,h));
      st.apply(wmemo.at(a)+1,i,tuple(t,a,x,h));
      wmemo.at(a) = i;
    }
  }
  vector<ll>cnt(2*100001,0);
  rep(i,m) {
    auto [a,b,c,d] = st.get(i);
    cnt.at(c) += d;
  }
  vector<pair<ll,ll>> ans;
  rep(i,cnt.size()) {
    if(cnt.at(i)==0) continue;
    ans.push_back(pair(i,cnt.at(i)));
  }
  cout << ans.size() << endl;
  for(auto [k,v] : ans) {
    cout << k << " " << v << endl;
  }

  return 0;
}
