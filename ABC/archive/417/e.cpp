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
  int T;cin>>T;
  while(T--) {
    int n,m,x,y;cin>>n>>m>>x>>y;x--;y--;
    vector g(n,vector<int>());
    rep(i,m) {
      int u,v;cin>>u>>v;u--;v--;
      g.at(u).push_back(v);
      g.at(v).push_back(u);
    }
    rep(i,n) sort(all(g.at(i)));
    vector<int> cur;
    vector<int> ans;
    vector<bool> seen(n,false);
    auto rec = [&](auto self,int v) -> void {
      cur.push_back(v);
      seen.at(v) = true;
      if(v==y) {
        if(ans.size()==0) ans = cur;
        return;
      }
      for(auto nv : g.at(v)) {
        if(seen.at(nv)) continue;
        self(self,nv);
      }
      cur.pop_back();
    };
    rec(rec,x);
    rep(i,ans.size()) {
      if(i) cout << " ";
      cout << ans.at(i)+1;
    }
    cout << endl;
  }

  return 0;
}
