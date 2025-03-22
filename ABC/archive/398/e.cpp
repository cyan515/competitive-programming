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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  vector g(n,vector<int>());
  vector es(n,vector<bool>(n,false));
  rep(i,n-1) {
    int u,v;cin>>u>>v;u--;v--;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
    es.at(u).at(v) = true;
  }
  vector<int> d(n,0);
  vector<bool> seen(n,false);
  auto dfs = [&](auto dfs,int v,int cur) -> void {
    d.at(v) = cur;
    for(auto nv : g.at(v)) {
      if(seen.at(nv)) continue;
      seen.at(nv) = true;
      dfs(dfs,nv,cur+1);
    }
  };
  seen.at(0) = true;
  dfs(dfs,0,0);
  set<pair<int,int>> st;
  rep(i,n) reps(j,i+1,n) {
    if(d.at(i)%2!=d.at(j)%2 && !es.at(i).at(j)) {
      st.insert(pair(i,j));
    }
  }
  if(st.size()%2) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
    int x,y;cin>>x>>y;x--;y--;
    st.erase(pair(x,y));
  }
  while(st.size()) {
    auto it = st.begin();
    auto [x,y] = *it;
    cout << x+1 << " " << y+1 << endl;
    st.erase(it);
    cin>>x>>y;
    if(x==-1) {
      return 0;
    }
    x--;y--;
    st.erase(pair(x,y));
  }

  return 0;
}
