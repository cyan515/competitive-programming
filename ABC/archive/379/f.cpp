#include <bits/stdc++.h>
#include <atcoder/segtree>
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
S op(S a,S b) {
  return max(a,b);
}
S e() {
  return -INF;
}


int main() {
  int n,Q;cin>>n>>Q;
  vector<int> h(n);cin>>h;
  segtree<S,op,e> st(n);
  rep(i,n) st.set(i,h.at(i));
  vector<int> a;
  a.push_back(n+1);
  vector qs(n+1,vector<pair<int,int>>());
  vector<int> ans(Q);
  rep(i,Q) {
    int l,r;cin>>l>>r;l--;r--;
    qs.at(r).push_back(pair(l,i));
  }
  for(int r=n-1;r>=0;r--) {
    while(a.back()<h.at(r)) a.pop_back();
    rep(j,qs.at(r).size()) {
      auto [l,idx] = qs.at(r).at(j);
      int ma = st.prod(l+1,r+1);
      int ok = 0;
      int ng = a.size();
      while(abs(ok-ng)>1) {
        int mid = (ok+ng)/2;
        if(a.at(mid)>=ma) ok = mid;
        else ng = mid;
      }
      ans.at(idx) = ok;
    }
    a.push_back(h.at(r));
  }
  rep(i,Q) cout << ans.at(i) << endl;

  return 0;
}
