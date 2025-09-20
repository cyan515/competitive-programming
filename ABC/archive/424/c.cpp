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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  vector g(n,vector<int>());
  queue<int> q;
  vector<int> dists(n,INF);
  rep(i,n) {
    int a,b;cin>>a>>b;a--;b--;
    if(a==-1&&b==-1) {
      q.push(i);
      dists.at(i) = 0;
      continue;
    }
    g.at(a).push_back(i);
    g.at(b).push_back(i);
  }
  while(q.size()) {
    auto v = q.front();q.pop();
    for(auto nv:g.at(v)) {
      if(dists.at(nv)!=INF) continue;
      dists.at(nv) = dists.at(v)+1;
      q.push(nv);
    }
  }
  int ans = 0;
  rep(i,n) ans += !!(dists.at(i)!=INF);
  cout << ans << endl;

  return 0;
}
