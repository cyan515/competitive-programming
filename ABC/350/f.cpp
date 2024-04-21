#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
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
using S = bool;
using F = bool;
bool op(bool a,bool b) {return a^b;}
bool e() {return false;}
bool mapping(F f,S s) {return op(f,s);}
bool comp(F f,F g) {return op(f,g);}
bool id() {return e();}

int main() {
  string s;cin>>s;
  string t = "";
  
  int n = s.size();
  lazy_segtree<S,op,e,F,mapping,comp,id> st(n);
  

  return 0;
}
