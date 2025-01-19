#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
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
using S = int;
using F = int;
S op(int a,int b) {
  return max(a,b);
}
S e() {
  return -INF;
}
S mapping(F f, S s) {
  return f+s;
}
F comp(F f,F g) {
  return f+g;
}
F id() {
  return 0;
}
int main() {
  int n;cin>>n;
  vector<int> l(n),r(n);
  rep(i,n) cin>>l.at(i)>>r.at(i);
  int Q;cin>>Q;
  lazy_segtree<S,op,e,F,mapping,comp,id> seg(500010);
  rep(i,500010) seg.set(i,i);
  rep(i,n) {
    int left = seg.max_right(0,[&](S s) -> bool {
      return s < l.at(i);
    });
    int right = seg.max_right(0,[&](S s) -> bool {
      return s <= r.at(i);
    });
    seg.apply(left,right,1);
  }
  while(Q--) {
    int x;cin>>x;
    cout << seg.get(x) << endl;
  }

  return 0;
}
