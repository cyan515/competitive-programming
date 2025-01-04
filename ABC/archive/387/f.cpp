#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint998244353;
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
  vector<ll> a(n);cin>>a;
  rep(i,n) a.at(i)--;
  vector g(n,vector<int>());
  scc_graph sg(n);
  vector<int> out_deg(n,0);
  rep(i,n) g.at(a.at(i)).push_back(i),sg.add_edge(a.at(i),i),out_deg.at(a.at(i))++;
  mint ans = 0;
  rep(x,m) {
    vector dp(n,fenwick_tree<mint>(m));
    for(auto v : sg.scc()) {
      if(v.size()>1||a.at(v.front())==v.front()) {
        for(auto ele : v) dp.at(ele).add(x,1);
      }
      else {
        rep(j,m) dp.at(v.front()).add(j,dp.at(a.at(v.front())).sum(j,m));
      }
    }
    mint tmp = 1;
    rep(i,n) {
      if(out_deg.at(i)!=0) continue;
      tmp *= dp.at(i).sum(0,m);
    }
    ans += tmp;
  }
  cout << ans.val() << endl;

  return 0;
}
