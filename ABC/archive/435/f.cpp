#include <bits/stdc++.h>
using namespace std;
#include <atcoder/segtree>
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
// height, index
using S = pair<int,int>;
S op(S a,S b) {
  if(a.first>b.first) return a;
  else return b;
}
S e() {
  return pair(-INF,-INF);
}

int main() {
  ll n;cin>>n;
  vector<ll> a(n);cin>>a;
  vector<ll> ord(n);
  rep(i,n) ord.at(i) = i;
  sort(rall(ord), [&](ll i,ll j) -> bool {
    return a.at(i)<a.at(j);
  });
  vector g(n,vector<ll>());
  segtree<S,op,e> seg(n);
  rep(i,n) seg.set(i,pair(a.at(i),i));
  ll ans = 0;
  ll cur = 0;
  auto dfs = [&](auto self,ll p,ll l,ll r) -> void {
    chmax(ans,cur);
    if(l==r) return;
    auto [ma,idx] = seg.prod(l,r);
    if(p!=-1) {
      g.at(p).push_back(idx);
      g.at(idx).push_back(p);
      cur += abs(p-idx);
    }
    self(self,idx,l,idx);
    self(self,idx,idx+1,r);
    if(p!=-1) cur -= abs(p-idx);
  };
  dfs(dfs,-1,0,n);
  cout << ans << endl;

  return 0;
}
