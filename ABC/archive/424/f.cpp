#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
using S = ll;
S op(S a,S b) {
  return min(a,b);
}
S e() {
  return LINF;
}
using F = ll;
F mapping(S s,F f) {
  return s+f;
}
F comp(F f,F g) {
  return f+g;
}
F id() {
  return 0LL;
}

int main() {
  int n,Q;cin>>n>>Q;
  lazy_segtree<S,op,e,F,mapping,comp,id> seg(2*n);
  rep(i,n*2) seg.set(i,0);
  while(Q--) {
    // rep(i,2*n) cout<<seg.get(i)<<" ";cout<<endl;
    int a,b;cin>>a>>b;a--;
    a*=2;
    b*=2;b--;
    // cout<<seg.get(a) << " "<<seg.get(b-1)<<" "<<seg.prod(a,b)<<endl;
    if(seg.get(a)!=seg.get(b-1) || seg.get(a)>seg.prod(a,b)) {
      cout << No << endl;
      continue;
    }
    cout << Yes << endl;
    seg.apply(a,b,1);
  }

  return 0;
}
