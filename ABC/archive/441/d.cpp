#include <bits/stdc++.h>
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
  int n,m,l;cin>>n>>m>>l;
  ll s,t;cin>>s>>t;
  vector g(n,vector<pair<ll,int>>());
  rep(i,m) {
    int u,v;cin>>u>>v;u--;v--;
    ll w;cin>>w;
    g.at(u).push_back(pair(w,v));
  }
  set<int> st;
  int len = 0;
  ll sum = 0;
  auto dfs = [&](auto self,int v) -> void {
    if(len==l) {
      if(s<=sum&&sum<=t) st.insert(v+1);
      return;
    }
    for(auto [w,nv] : g.at(v)) {
      len++;
      sum += w;
      self(self,nv);
      len--;
      sum -= w;
    }
  };
  dfs(dfs,0);
  vector<int> ans(all(st));
  rep(i,ans.size()) {
    if(i)cout<<" ";
    cout << ans.at(i);
  }
  cout << endl;

  return 0;
}
