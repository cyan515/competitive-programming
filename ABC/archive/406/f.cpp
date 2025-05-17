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
int op(int a,int b) {
  return a+b;
}
int e() { 
  return 0;
}
int main() {
  int n;cin>>n;
  vector<int> us(n),vs(n);
  vector g(n,vector<int>());
  rep(i,n-1) {
    int u,v;cin>>u>>v;u--;v--;
    us.at(i) = u;
    vs.at(i) = v;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
  }
  vector<int> in(n),out(n);
  int cur = 0;
  vector<int> p(n,-1);
  vector<int> mp(n);
  mp.at(0) = n-1;
  segtree<int,op,e> seg(n);
  rep(i,n) seg.set(i,1);
  auto dfs = [&](auto self,int v,int par) -> void {
    for(auto nv : g.at(v)) {
      if(nv==par) continue;
      p.at(nv) = v;
      in.at(nv) = cur;
      self(self,nv,v);
      out.at(nv) = cur+1;
      mp.at(nv) = cur;
      cur++;
    }
  };
  ll sum = n;
  dfs(dfs,0,-1);
  int Q;cin>>Q;
  out.at(0) = n;
  while(Q--) {
    int t;cin>>t;
    if(t==1) {
      int x,w;cin>>x>>w;x--;
      seg.set(mp.at(x),seg.get(mp.at(x))+w);
      sum += w;
    } else {
      int y;cin>>y;y--;
      int u = us.at(y);
      int v = vs.at(y);
      if(p.at(v)==u) {
        swap(u,v);
      }
      ll xx = seg.prod(in.at(u),out.at(u));
      ll yy = sum - xx;
      cout << abs(xx-yy) << endl;
    }
  }

  return 0;
}
