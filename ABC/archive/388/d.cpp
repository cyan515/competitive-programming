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
using S = ll;
using F = ll;
S op(S a,S b) {
  return a;
}
S e() {
  return -LINF;
}
S mapping(F f,S s) {
  return f+s;
}
F comp(F f,F g) {
  return f+g;
}
F id() {
  return 0;
}
int main() {
  ll n;cin>>n;
  vector<ll>a(n);cin>>a;
  lazy_segtree<S,op,e,F,mapping,comp,id> seg(n);
  rep(i,n) seg.set(i,a.at(i));
  rep(i,n) {
    ll cnt = seg.get(i);
    cnt = min(n,i+cnt+1);
    seg.apply(i+1,cnt,1);
    seg.set(i,seg.get(i)-(cnt-(i+1)));
  }
  rep(i,n) {
    if(i) cout << " ";
    cout << seg.get(i);
  }
  cout << endl;

  return 0;
}
