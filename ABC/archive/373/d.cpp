#include <bits/stdc++.h>
#include <atcoder/dsu>
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

int main() {
  ll n,m;cin>>n>>m;
  vector g(n,vector<pair<ll,ll>>());
  dsu uf(n);
  rep(i,m) {
    ll u,v,w;cin>>u>>v>>w;u--;v--;
    uf.merge(u,v);
    g.at(u).push_back(pair(w,v));
    g.at(v).push_back(pair(-w,u));
  }
  vector<ll> ans(n,LINF);
  for(auto& vec : uf.groups()) {
    ans.at(vec.front()) = 0;
    queue<int> q;
    q.push(vec.front());
    while(q.size()) {
      int v = q.front();q.pop();
      for(auto [nw,nv] : g.at(v)) {
        if(ans.at(nv)!=LINF) continue;
        ans.at(nv) = ans.at(v) + nw;
        q.push(nv);
      }
    }
    ll ma = -LINF;
    ll mi = LINF;
    for(auto ele : vec) {
      chmax(ma,ans.at(ele));
      chmin(mi,ans.at(ele));
    }
    if(mi<-1000000000000000000LL) {
      for(auto ele : vec) {
        ans.at(ele) = ans.at(ele)+mi-1000000000000000000LL;
      }
    } else if(ma>1000000000000000000LL) {
      for(auto ele : vec) {
        ans.at(ele) = ans.at(ele)-ma+1000000000000000000LL
      }
    }
  }
  rep(i,n) {
    if(i) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;

  return 0;
}
