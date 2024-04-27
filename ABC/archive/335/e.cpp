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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n,m;cin>>n>>m;
  vector<int> a(n);
  cin>>a;
  vector g(n,set<int>());
  dsu uf(n);
  vector<pair<int,int>> uv(m);
  rep(i,m) {
    int u,v;cin>>u>>v;u--;v--;
    if(a.at(u)>a.at(v)) swap(u,v);
    if(a.at(u)==a.at(v)) uf.merge(u,v);
    uv.at(i) = make_pair(u,v);
  }
  for(auto [u,v] : uv) {
    u = uf.leader(u);
    v = uf.leader(v);
    if(u==v) continue;
    if(a.at(u)!=a.at(v)) g.at(u).insert(v);
  }
  vector<int> in(n,0);
  rep(i,n) for(auto ele : g.at(i)) {
    in.at(ele)++;
  }
  vector<int> li;
  for(auto ele : g.at(0)) {
    in.at(ele)--;
    if(in.at(ele)==0) li.push_back(ele);
  }
  int len = 1;
  bool flg = false;
  while(li.size()) {
    vector<int> nli;
    rep(i,li.size()) {
      for(auto ele : g.at(li.at(i))) {
        in.at(ele)--;
        if(in.at(ele)==0) {
          nli.push_back(ele);
          if(ele == n-1) flg = true;
        }
      }
    }
    li = nli;
    len++;
  }
  if(len==1) {
    if(a.at(0)==a.at(n-1) && uf.leader(0)==uf.leader(n-1)) {
      cout << 1 << endl;
    } else if(flg) cout << 1 << endl;
    else cout << 0 << endl;
  }
  else if(flg) cout << len << endl;
  else cout << 0 << endl;

  exit(0);
}
