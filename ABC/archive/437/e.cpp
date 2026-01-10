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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  vector<int> x(n),y(n);
  rep(i,n) cin>>x.at(i)>>y.at(i);
  vector<map<int,int>> g(n+1);
  vector<int> mp(n+1);
  mp.at(0) = 0;
  vector node(n+1,vector<int>());
  node.at(0).push_back(0);
  {
    int cur = 0;
    rep(i,n) {
      if(!g.at(mp.at(x.at(i))).contains(y.at(i))) {
        g.at(mp.at(x.at(i)))[y.at(i)] = ++cur;
        node.at(cur).push_back(i+1);
      }
      mp.at(i+1) = cur;
    }
  }
  vector<int> ans;
  auto dfs = [&](auto self,int v) -> void {
    if(v) ans.push_back(v);
    for(auto [k,val] : g.at(v)) {
      for(auto ele : node.at(v)) {
        ans.push_back(ele);
      }
      self(self,val);
    }
  };
  dfs(dfs,0);
  rep(i,n) {
    if(i)cout<<" ";
    cout<<ans.at(i);
  }
  cout << endl;

  return 0;
}
