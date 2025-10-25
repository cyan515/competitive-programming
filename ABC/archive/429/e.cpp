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
  int n,m;cin>>n>>m;
  vector g(n,vector<int>());
  rep(i,m) {
    int u,v;cin>>u>>v;u--;v--;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
  }
  string s;cin>>s;
  // dist, start
  vector dist(n,vector<pair<int,int>>());
  // vertex, start
  queue<pair<int,int>> q;
  rep(i,n) {
    if(s.at(i)=='S') {
      q.push(pair(i,i));
      dist.at(i).push_back(pair(0,i));
    }
  }
  while(q.size()) {
    auto [v,start] = q.front();q.pop();
    int vdist = INF;
    for(auto [dd,ss] : dist.at(v)) {
      if(ss==start) vdist = dd;
    }
    for(auto nv : g.at(v)) {
      bool seen = false;
      for(auto [dd,ss] : dist.at(nv)) {
        if(ss==start) seen = true;
      }
      if(seen) continue;
      int ndist = vdist+1;
      dist.at(nv).push_back(pair(ndist,start));
      sort(all(dist.at(nv)));
      while(dist.at(nv).size()>2) dist.at(nv).pop_back();
      bool updated = false;
      for(auto ele : dist.at(nv)) {
        if(ele == pair(ndist,start)) updated = true;
      }
      if(updated) q.push(pair(nv,start));
    }
  }
  rep(i,n) {
    if(s.at(i)=='D') {
      cout << dist.at(i).at(0).first + dist.at(i).at(1).first << endl;
    }
  }

  return 0;
}
