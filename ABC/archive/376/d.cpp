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

int main() {
  ll n,m;cin>>n>>m;
  vector g(n,vector<ll>());
  rep(i,m) {
    int a,b;cin>>a>>b;a--;b--;
    g.at(a).push_back(b);
  }
  queue<int> q;
  vector<int> d(n,INF);
  vector<bool> seen(n,false);
  for(auto ele : g.at(0)) {
    d.at(ele) = 1;
    q.push(ele);
    seen.at(ele) = true;
  }
  while(q.size()) {
    int v = q.front();q.pop();
    for(auto nv : g.at(v)) {
      if(seen.at(nv)) continue;
      seen.at(nv) = true;
      d.at(nv) = d.at(v)+1;
      q.push(nv);
    }
  }
  int ans = d.at(0);
  if(ans==INF) ans=-1;
  cout << ans << endl;

  return 0;
}
