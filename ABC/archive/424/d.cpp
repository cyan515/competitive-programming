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
vector<pair<int,int>> dir4 = {{0,1},{0,-1},{1,0},{-1,0},};
vector<pair<int,int>> dir8 = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1},};

int main() {
  int T;cin>>T;
  while(T--) {
    int h,w;cin>>h>>w;
    vector<string> s(h);cin>>s;
    auto in = [&](unsigned i, unsigned j) -> bool {
      return i<h&&j<w;
    };
    auto f = [&](int i,int j) -> bool {
      bool ret = true;
      rep(di,2) rep(dj,2) {
        int ni = i+di;
        int nj = j+dj;
        if(!in(ni,nj)) {
          return false;
        }
        ret &= s.at(ni).at(nj)=='#';
      }
      return ret;
    };
    auto cnt = [&](int i,int j) -> int {
      int ret = 0;
      reps(di,-1,1) reps(dj,-1,1) {
        int ni = i+di;
        int nj = j+dj;
        if(!in(ni,nj)) continue;
        if(f(ni,nj)) ret++;
      }
      return ret;
    };
    vector x(h,vector<int>(w,0));
    rep(i,h) rep(j,w) x.at(i).at(j) = cnt(i,j);
    // cnt, i, j
    priority_queue<tuple<int,int,int>> q;
    set<tuple<int,int,int>> del;
    rep(i,h) rep(j,w) {
      if(x.at(i).at(j)==0) continue;
      q.push(tuple(x.at(i).at(j),i,j));
    }
    int ans = 0;
    while(q.size()) {
      auto [xx,ii,jj] = q.top();q.pop();
      if(del.count(tuple(xx,ii,jj))) {
        del.erase(tuple(xx,ii,jj));
        continue;
      }
      ans++;
      s.at(ii).at(jj) = '.';
      x.at(ii).at(jj) = 0;
      for(auto [di,dj] : dir8) {
        int ni = ii+di;
        int nj = jj+dj;
        if(!in(ni,nj)) continue;
        int nx = cnt(ni,nj);
        if(x.at(ni).at(nj)==nx) continue;
        del.insert(tuple(x.at(ni).at(nj),ni,nj));
        x.at(ni).at(nj) = nx;
        if(nx>0) q.push(tuple(nx,ni,nj));
      }
    }
    cout << ans << endl;
  }

  return 0;
}
