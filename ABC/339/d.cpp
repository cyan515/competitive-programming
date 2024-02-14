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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n;cin>>n;
  vector<string> s(n);cin>>s;
  queue<tuple<int,int,int,int>> q;
  vector dists(n,vector(n,vector(n,vector<int>(n,INF))));
  vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
  auto ok = [&](int a,int b) -> bool {
    if(a<0 || a>=n || b<0 || b>=n) return false;
    if(s.at(a).at(b)=='#') return false;
    return true;
  };
  int ans = INF;
  {
    int a = -1,b=-1,c=-1,d=-1;
    rep(i,n) rep(j,n) {
      if(s.at(i).at(j)=='P') {
        if(a==-1) {
          a = i; b = j;
        } else {
          c = i; d = j;
        }
      }
    }
    q.emplace(a,b,c,d);
    dists.at(a).at(b).at(c).at(d) = 0;
  }
  
  while(q.size()) {
    auto [a,b,c,d] = q.front();q.pop();
    for(auto [dx,dy] : dir) {
      int na = a+dx;
      int nb = b+dy;
      int nc = c+dx;
      int nd = d+dy;
      if(!ok(na,nb)) {
        na = a;
        nb = b;
      }
      if(!ok(nc,nd)) {
        nc = c;
        nd = d;
      }
      if(dists.at(na).at(nb).at(nc).at(nd)!=INF) continue;
      dists.at(na).at(nb).at(nc).at(nd) = dists.at(a).at(b).at(c).at(d)+1;
      q.emplace(na,nb,nc,nd);
    }
  }
  rep(i,n) rep(j,n) {
    ans = min(ans,dists.at(i).at(j).at(i).at(j));
  }
  if(ans==INF) ans = -1;
  cout << ans << endl;

  exit(0);
}
